#pragma once

template <typename T>
int comparationNumbers(T* data1, T* data2)
{
	if (*data1 < *data2)
		return -1;
	if (*data1 == *data2)
		return 0;
	return 1;
}