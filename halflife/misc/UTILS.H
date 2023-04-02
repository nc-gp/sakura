
#ifndef  UTILS_H
#define  UTILS_H

template <class T> T inline MakePtr(void* Base,DWORD Offset=0)
{
	return reinterpret_cast<T>(reinterpret_cast<DWORD>(Base) + Offset);
}

void Protect(void* addr,int size)
{
	static DWORD realsize;
	static DWORD old;
	if (size!=-1)
	{
    realsize = size;
	VirtualProtect(addr,realsize,PAGE_EXECUTE_READWRITE,&old);
	}
	else 
	{   
		DWORD dummy;
		VirtualProtect(addr,realsize,old,&dummy);
	}
}

template <class T> void inline RandomOverwrite(T addr)
{
   BYTE* startaddr = reinterpret_cast<BYTE*>(addr);
   BYTE* endaddr = reinterpret_cast<BYTE*>(addr) + sizeof(T);
   Protect(startaddr,sizeof(T));
   for (;startaddr<endaddr;startaddr++)
	   *startaddr = rand();
   Protect(startaddr,-1);
}

bool __fastcall ScanPattern_FF15calladr(BYTE* start, DWORD calladr,int array_size,BYTE **pos )
{
	array_size-=6;
	while(array_size)
	{
 		if( start[0]==0xFF && 
			start[1]==0x15 &&
			*(DWORD*)(start+2)==calladr ) { *pos = start; return true; }

		array_size--;
		start++;
	}
	return false;
}

bool __fastcall ScanPattern_fixstackandret(BYTE* start,BYTE stacklen,int array_size,BYTE **pos)
{
	if (stacklen)
	{
	array_size-=6;
	while(array_size)
	{
 		if( start[0]==0x83 && 
			start[1]==0xC4 &&
			start[2]==stacklen &&
			start[3]==0xC3  ) { *pos = start; return true; }
		array_size--;
		start++;
	}
	}
	else
	{
		array_size-=1;
		while(array_size)
	    {
 		if( start[0]==0xC3 ) { *pos = start; return true; }
		array_size--;
		start++;
	    }
	}
	return false;
}

bool __fastcall ScanPattern_8B2Dcalladr(BYTE* start, DWORD calladr,int array_size,BYTE **pos )
{
	array_size-=6;
	while(array_size)
	{
 		if( start[0]==0x8B && 
			start[1]==0x2D &&
			*(DWORD*)(start+2)==calladr ) { *pos = start; return true; }

		array_size--;
		start++;
	}
	return false;
}

bool __fastcall ScanPattern_8B35calladr(BYTE* start, DWORD calladr,int array_size,BYTE **pos )
{
	array_size-=6;
	while(array_size)
	{
 		if( start[0]==0x8B && 
			start[1]==0x35 &&
			*(DWORD*)(start+2)==calladr ) { *pos = start; return true; }

		array_size--;
		start++;
	}
	return false;
}

#endif
