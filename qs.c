#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// vertauscht 2 Element via Zeigerzugriff
void swap(int *a, int *b);

// Das Array [left, right[ wird quicksort paritioniert
// Achtung: left ist inklusive und right nicht mehr Teil des arrays!
// Nimm das letzte Element des Array als Pivot Element (array[right-1])
// benutze void swap(int*, int*) zum vertauschen von Elementen
// Gibt den Index Pivot Elements im Array zurueck
int partition(int left, int right, int array[]);

// Quicksort: sortiert ein Array [left, right[ also z.B.:
// int a[500]; kann via quicksort(0,500,a); sortiert werden
// Ruft partition auf und sich selbst links und rechts vom Pivot Element
// Achtung: Rekursion muss auch wieder beendet werden
void quicksort(int left, int right, int array[]);

// Testtreiber fuer quicksort, nicht veraendern!
int main(int argc, char **argv)
{
	int a[32];

	for (;;)	{
		for (int i=0; i<32; ++i)	{
			a[i] = rand() % 100;
		}

		int size = rand() % 32;

		quicksort(0, size, a);

		int old = -1;
		for (int i=0; i<size; ++i)	{
			if (old != -1) assert(old <= a[i]);
			printf("%d ", a[i]);
			old = a[i];
		}
		printf("\n");
	}
}
