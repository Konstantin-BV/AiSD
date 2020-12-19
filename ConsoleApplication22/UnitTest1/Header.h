#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>

int check(char* formula)
{
	int i = 0, n = i;
	while (i < strlen(formula))
	{
		n = i;
		if ((formula[i] == '*' || formula[i] == '/' || formula[i] == '+' || formula[i] == '^') && !(formula[i + 1] == '*' || formula[i + 1] == '/' || formula[i + 1] == '+' || formula[i + 1] == '^' || formula[i - 1] == '*' || formula[i - 1] == '/' || formula[i - 1] == '+' || formula[i - 1] == '*' || formula[i - 1] == '^'))
			i++;

			if (formula[i] == 'e')
			{
				i++;
			}
			if (formula[i] == 'p' && formula[i + 1] == 'i')
			{
				i++;
				i++;
			}
		if (formula[i + 3])
			if (formula[i] == 'c' && formula[i + 1] == 't' && formula[i + 2] == 'g')
			{
				i = i + 3;
			}
		if (formula[i + 4])
			if (formula[i] == 'q' && formula[i + 1] == 's' && formula[i + 2] == 'r' && formula[i + 3] == 't')
			{
				i = i + 4;
			}
		if (formula[i + 2])
			if (formula[i] == 't' && formula[i + 1] == 'g')
			{
				i = i + 2;
			}
		if (formula[i + 3])
			if (formula[i] == 'c' && formula[i + 1] == 'o' && formula[i + 2] == 's')
			{
				i = i + 3;
			}
		if (formula[i + 3])
			if (formula[i] == 's' && formula[i + 1] == 'i' && formula[i + 2] == 'n')
			{
				i = i + 3;
			}
		if (formula[i + 3])
			if (formula[i] == 'l' && formula[i + 1] == 'o' && formula[i + 2] == 'g')
			{
				i = i + 3;
			}
		if (formula[i] == '.' && int(formula[i - 1]) >= 48 && int(formula[i - 1]) <= 58 && int(formula[i + 1]) >= 48 && int(formula[i + 1]) <= 58)
			i++;
		if (int(formula[i]) >= 48 && int(formula[i]) <= 58)
			i++;
		if (formula[i] == '(' || formula[i] == ')')
			i++;
		if (i == n)
			return i+1;
	}
	return -1;
}

int calc(double* numbers, char* formula, int* n, char act1, char act2)
{
	int i = 0, j;
	double p;
	while (i < *n - 1)
		for (i = 0; i < *n - 1; i++)
			if (formula[i] == act1 || formula[i] == act2)
			{
				if (formula[i] == '*') numbers[i] *= numbers[i + 1];
				if (formula[i] == '/') numbers[i] /= numbers[i + 1];
				if (formula[i] == '+') numbers[i] += numbers[i + 1];
				if (formula[i] == '-') numbers[i] -= numbers[i + 1];
				if (formula[i] == '^')
				{
					p = numbers[i];
					for (int k = 1; k < numbers[i + 1]; k++)
					{
						numbers[i] = numbers[i] * p;
					}
				}
				if (formula[i] == 'l')
					numbers[i] = log(numbers[i]);
				if (formula[i] == 's')
					numbers[i] = sin(numbers[i]);
				if (formula[i] == 'c')
					numbers[i] = cos(numbers[i]);
				if (formula[i] == 't')
					numbers[i] = tan(numbers[i]);
				if (formula[i] == 'w')
					numbers[i] = 1 / tan(numbers[i]);
				if (formula[i] == 'q')
					numbers[i] = sqrt(numbers[i]);
				if (formula[i] == '.')
				{
					while (!(numbers[i + 1] < 1))
					{
						numbers[i + 1] = numbers[i + 1] / 10;
					}
					numbers[i] = numbers[i] + numbers[i + 1];
				}
				for (j = i; j < *n - 2; j++)formula[j] = formula[j + 1];
				for (j = i + 1; j < *n - 1; j++)numbers[j] = numbers[j + 1];
				--* n;
				break;
			}
	return 0;
}

double calculator(char* formula)
{
	char acts[30];
	char* new_formula;
	int i, quantity, b, e, t = -2;
	double numbers[30];

	if (strlen(formula))
	{
		b = quantity = 0;
		for (i = 0; formula[i]; i++)
		{
			if (formula[i] == '(')
			{
				t = i + 1;
				while (formula[t] != ')')
				{
					t++;
				}
				new_formula = new char[t - i - 1];
				for (int k = 0; k < t - i - 1; k++)
					new_formula[k] = formula[k + i + 1];
				e = i;
				if (formula[i + 1]) acts[quantity] = formula[t + 1];
				else e++;
				formula[e] = 0;
				numbers[quantity++] = calculator(new_formula);
				b = i + 1;
				i = t + 1;
			}
			if (formula[i + 2])
				if (formula[i] == 'e')
				{
					e = i;
					if (formula[i + 1]) acts[quantity] = formula[i+1];
					else e++;
					formula[e] = 0;
					//f[ns++] = M_E;
					b = i + 1;
				}
			if (formula[i + 2])
				if (formula[i] == 'p' && formula[i + 1] == 'i')
				{
					e = i;
					if (formula[i + 1]) acts[quantity] = formula[i + 2];
					else e++;
					formula[e] = 0;
					//f[ns++] = M_PI;
					b = i + 1;
				}
			if (formula[i + 3])
				if (formula[i] == 'c' && formula[i + 1] == 't' && formula[i + 2] == 'g')
				{
					e = i;
					if (formula[i + 1]) acts[quantity] = 'w';
					else e++;
					formula[e] = 0;
					numbers[quantity++] = atof(formula + b + 3);
					b = i + 1;
				}
			if (formula[i + 4])
				if (formula[i] == 'q' && formula[i + 1] == 's' && formula[i + 2] == 'r' && formula[i + 3] == 't')
				{
					e = i;
					if (formula[i + 1]) acts[quantity] = formula[i];
					else e++;
					formula[e] = 0;
					numbers[quantity++] = atof(formula + b + 4);
					b = i + 1;
				}
			if (formula[i + 2])
				if (formula[i] == 't' && formula[i + 1] == 'g')
				{
					e = i;
					if (formula[i + 1]) acts[quantity] = formula[i];
					else e++;
					formula[e] = 0;
					numbers[quantity++] = atof(formula + b + 2);
					b = i + 1;
				}
			if (formula[i + 3])
				if (formula[i] == 'c' && formula[i + 1] == 'o' && formula[i + 2] == 's')
				{
					e = i;
					if (formula[i + 1]) acts[quantity] = formula[i];
					else e++;
					formula[e] = 0;
					numbers[quantity++] = atof(formula + b + 3);
					b = i + 1;
				}
			if (formula[i + 3])
				if (formula[i] == 's' && formula[i + 1] == 'i' && formula[i + 2] == 'n')
				{
					e = i;
					if (formula[i + 1]) acts[quantity] = formula[i];
					else e++;
					formula[e] = 0;
					numbers[quantity++] = atof(formula + b + 3);
					b = i + 1;
				}
			if (formula[i + 3])
				if (formula[i] == 'l' && formula[i + 1] == 'o' && formula[i + 2] == 'g')
				{
					e = i;
					if (formula[i + 1]) acts[quantity] = formula[i];
					else e++;
					formula[e] = 0;
					numbers[quantity++] = atof(formula + b + 3);
					b = i + 1;
				}
			if (i && (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/' || formula[i] == '^' || formula[i] == '.' || !formula[i + 1]) && !(t + 1 == i))
			{
				e = i;
				if (formula[i + 1]) acts[quantity] = formula[i];
				else e++;
				if (formula[i + 1] != '(')
					formula[e] = 0;
				numbers[quantity++] = atof(formula + b);
				b = i + 1;
			}
		}
		calc(numbers, acts, &quantity, '.', ' ');
		calc(numbers, acts, &quantity, 'w', ' ');
		calc(numbers, acts, &quantity, 'q', ' ');
		calc(numbers, acts, &quantity, 't', ' ');
		calc(numbers, acts, &quantity, 's', ' ');
		calc(numbers, acts, &quantity, 'c', ' ');
		calc(numbers, acts, &quantity, 'l', ' ');
		calc(numbers, acts, &quantity, '^', ' ');
		calc(numbers, acts, &quantity, '*', '/');
		calc(numbers, acts, &quantity, '+', '-');
		return numbers[0];
	}
}