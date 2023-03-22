const inputElement = document.querySelector('#user-input-field')
const outputElement = document.querySelector('#xor-output-field')
const convertElement = document.querySelector('#convert-button')

let symbols = " !\"#$%&'()*+'-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

const toAscii = (character) => {
	const loc = symbols.indexOf(character)

	if (loc > -1) {
		const asciiDecimal = 32 + loc
		return asciiDecimal
	}

	return 0;
}

const decToHex = (decimal) => {
	const hexChars = "0123456789ABCDEF"
	const a = decimal % 16
	const b = (decimal - a) / 16
	const hex = `${hexChars.charAt(b)}${hexChars.charAt(a)}`
	const l = hexChars.charAt(a)
	const h = hexChars.charAt(b)
	return hex
}

const randByte = () => { return Math.floor(Math.random()* 256 % 256) }

const blub = () => {
	const s1 = inputElement.value
	const xValueStart = randByte()
	const xRefKill = `0x${decToHex(randByte())}${decToHex(randByte())}${decToHex(randByte())}${decToHex(randByte())}`

	let finalLen = s1.length + 1

	let hexSequence = '"'
	let xValue = xValueStart

	for (let i = 0; i < s1.length; i++) {
		let ch = s1.charAt(i)
		let chVal

		if (ch == "\\") {
			i++
			ch = s1.charAt(i)
			if (ch == "0") {
			chVal = 0
			} else if (ch == "n") {
				chVal = 10
			} else if (ch == "\\") {
				chVal = toAscii("\\")
			} else if (ch == "r") {
				chVal = 13
			} else {
				outputElement.value = `invalid control sequence: \\${ch}`
			}
			finalLen--
		} else if (ch == "|") {
			chVal = 0
		} else {
			chVal = toAscii(ch)
			if (chVal == 0) {
				outputElement.value = `invalid character: ${ch}`
				return
			}
		}

		chVal ^= xValue
		xValue += 1
		xValue %= 256
		hexSequence += `\\x${decToHex(chVal)}`
	}

	hexSequence += '"'

	const s2 = `/*${s1}*/XorStr<0x${decToHex(xValueStart)},${finalLen},${xRefKill}>(${hexSequence} + ${xRefKill}).s`

	outputElement.value = s2
	outputElement.focus()
	outputElement.select()
}

convertElement.addEventListener('click', () => { blub() })