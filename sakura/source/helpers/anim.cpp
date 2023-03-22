#include "../client.h"

float Sakura::Animation::QuadEaseInOut(float t, float b, float c, float d)
{
    t /= d / 2;
    if (t < 1) return c / 2 * t * t + b;
    t--;
    return -c / 2 * (t * (t - 2) - 1) + b;
}

void Sakura::Animation::Calculate(double* variable, double &changeTimestamp, double value, double maxValue, double animationTime)
{
	if (variable[current] != value)
	{
		if (changeTimestamp + animationTime >= client_state->time)
			variable[previous] = variable[calculated];

		variable[current] = value;
		changeTimestamp = client_state->time;
	}

	float elapsed_time = static_cast<float>(client_state->time - changeTimestamp);
	float t = elapsed_time / static_cast<float>(animationTime);
	float eased_variable = QuadEaseInOut(t, variable[previous], variable[current] - variable[previous], 1.f);

	if (elapsed_time >= animationTime)
	{
		variable[calculated] = variable[current];
		variable[previous] = variable[current];
	}
	else
	{
		variable[calculated] = eased_variable;
	}

	if (variable[calculated] > maxValue)
		variable[calculated] = maxValue;
}