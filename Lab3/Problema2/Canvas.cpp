#include "Canvas.h"
#include <algorithm>
#include <cmath>
using namespace std;

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->canvas = new char* [height];
	for (int i = 0; i < height; i++)
	{
		this->canvas[i] = new char[width];
		for (int j = 0; j < width; j++)
		{
			this->canvas[i][j] = ' ';
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	this->canvas[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	int signX = (x1 < x2) ? 1 : -1;
	int signY = (y1 < y2) ? 1 : -1;
	int error = dx - dy;
	SetPoint(x2, y2, ch);
	while (x1 != x2 || y1 != y2)
	{
		SetPoint(x1, y1, ch);
		int error2 = error * 2;
		if (error2 > -dy)
		{
			error -= dy;
			x1 += signX;
		}
		if (error2 < dx)
		{
			error += dx;
			y1 += signY;
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = max(0, y - ray); i <= min(this->height, y + ray); ++i)
	{
		for (int j = max(0, x - ray); j <= min(this->width, x + ray); ++j)
		{
			int val = (i - y) * (i - y) + (j - x) * (j - x);
			int thickness = ray * 2;
			if (val <= ray * ray && val >= ray * ray - thickness)
			{
				SetPoint(j, i, ch);
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = max(0, y - ray); i <= min(this->height, y + ray); ++i)
	{
		for (int j = max(0, x - ray); j <= min(this->width, x + ray); ++j)
		{
			if ((i - y) * (i - y) + (j - x) * (j - x) <= ray * ray)
			{
				SetPoint(j, i, ch);
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	DrawLine(left, top, left, bottom, ch);
	DrawLine(left, top, right, top, ch);
	DrawLine(right, top, right, bottom, ch);
	DrawLine(left, bottom, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; ++i)
	{
		for (int j = left; j <= right; ++j)
		{
			this->canvas[i][j] = ch;
		}
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			this->canvas[i][j] = ' ';
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			printf("%c", this->canvas[i][j]);
		}
		printf("\n");
	}
}