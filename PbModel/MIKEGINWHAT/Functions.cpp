#include "Functions.h"

int GetLength(const char* string)
{
	int length = 0;
	for (int i = 0; string[i] != '\0'; i++)
		length++;
	return length;
}

int comparename(const Student& b1, const Student& b2)
{
	const char* nameB1 = b1.getname();
	const char* nameB2 = b2.getname();
	int lengthB1 = GetLength(nameB1);
	int lengthB2 = GetLength(nameB2);

	if (lengthB1 < lengthB2)
		return -1;
	if (lengthB1 > lengthB2)
		return 1;
	for (int i = 0; i < lengthB1; i++)
	{
		if (nameB1[i] < nameB2[i])
			return -1;
		if (nameB1[i] > nameB2[i])
			return 1;
	}
	return 0;
}

int comparemate(const Student& b1, const Student& b2)
{
	if (b1.getmate() > b2.getmate())
		return 1;
	else
		if (b1.getmate() == b2.getmate())
			return 0;
		else
			return -1;
}

int compareengleza(const Student& b1, const Student& b2)
{
	if (b1.getengleza() > b2.getengleza())
		return 1;
	else
		if (b1.getengleza() == b2.getengleza())
			return 0;
		else
			return -1;
}

int compareistorie(const Student& b1, const Student& b2)
{
	if (b1.getistorie() > b2.getistorie())
		return 1;
	else
		if (b1.getistorie() == b2.getistorie())
			return 0;
		else
			return -1;
}

int comparemedie(const Student& b1, const Student& b2)
{
	if (b1.medie() > b2.medie())
		return 1;
	else
		if (b1.medie() == b2.medie())
			return 0;
		else
			return -1;
}