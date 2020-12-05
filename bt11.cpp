// 11. test mang cap phat dong

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void inputArray(int a[], int n)
{
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
}

void outputArray(int a[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
}

void reverse(int a[], int n)
{
	for(int i=0; i<n/2; i++)
	{
		int tmp = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = tmp;
	}
	outputArray(a,n);
}

void sum_of_arr(int a[], int n)
{
	int sum = 0;
	for(int i=0; i<n; i++)
		sum += a[i];
	printf("sum of array is: %d", sum);
}

void mul_of_arr(int a[], int n)
{
	long long int mul = 1;
	for(int i=0; i<n; i++)
		mul *= a[i];
	printf("mul of array is: %lli", mul);
}

void choose_math(int &k, int arr[], int n)
{
	printf("1. sum\n2. mul\n");
	scanf("%d", &k);
	switch(k)
	{
		case 1: sum_of_arr(arr,n); break;
		case 2: mul_of_arr(arr,n); break;
		default:
		{
			exit(0);
			break;
		}
	}
}

bool square(int x)
{
	int i = 2;
	while(i <= x/2)
	{
		if(i*i == x)
		{
			return true;
			break;
		}
		else
			i++;
	}
	return false;
}

void square_num(int a[], int n)
{
	int count = 0;
	for(int i=0; i<n; i++)
		if(square(a[i]))
		{
			count++;
			printf("%d ", a[i]);
		}
	printf("\nco %d so chinh phuong.", count);
}

bool perfect(int x)
{
	int sum = 0;
	if(x == 0)
		return false;
	for(int i=1; i<x; i++)
	{
		if(x%i == 0)
		{
			sum += i;
		}
	}
	if(sum == x)
		return true;
	return false;
}


void perfect_num(int a[], int n)
{
	int count = 0;
	for(int i=0; i<n; i++)
		if(perfect(a[i]))
		{
			count++;
			printf("%d ", a[i]);
		}
	printf("\nco %d so hoan hao.", count);
}

bool prime(int x)
{
	if(x < 2)
		return false;
	else
	{
		for(int i=2; i<x; i++)
		{
			if(x % i == 0)
				return false;
		}
	}
	return true;;
}

void prime_num(int a[], int n)
{
	int count = 0;
	for(int i=0; i<n; i++)
		if(prime(a[i]))
		{
			count++;
			printf("%d ", a[i]);
		}
	printf("\nco %d so nguyen to.", count);
}

void even_odd(int a[], int n)
{
	int count_even=0, count_odd=0;
	for(int i=0; i<n; i++)
		if(a[i] & 1)
			count_odd++;
		else
			count_even++;
	printf("co %d so chan: ", count_even);
	for(int i=0; i<n; i++)
		if(a[i] % 2 == 0)
			printf("%d ", a[i]);
	printf("\nco %d so le: ", count_odd);
	for(int i=0; i<n; i++)
		if(a[i] & 1)
			printf("%d ", a[i]);
}

void positive_negative(int a[], int n)
{
	int count_po=0, count_ne=0, count_0=0;
	for(int i=0; i<n; i++)
		if(a[i] > 0)
			count_po++;
		else
		{
			if(a[i]<0)
				count_ne++;
			else
				count_0++;
		}
	printf("co %d so duong: ", count_po);
	for(int i=0; i<n; i++)
		if(a[i] > 0)
			printf("%d ", a[i]);
	printf("\nco %d so 0. ", count_0);
	printf("\nco %d so am: ", count_ne);
	for(int i=0; i<n; i++)
		if(a[i] < 0)
			printf("%d ", a[i]);
}

void choose_find_and_count(int &k, int arr[], int n)
{
	printf("1. square num\n2. perfect num\n3. prime num\n4. even & odd\n5. positive & negative\n");
	scanf("%d", &k);
	switch(k)
	{
		case 1: square_num(arr,n); break;
		case 2: perfect_num(arr,n); break;
		case 3: prime_num(arr,n); break;
		case 4: even_odd(arr,n); break;
		case 5: positive_negative(arr,n); break;
		default:
		{
			exit(0);
			break;
		}
	}
}

int Gcd(int x, int y)
{
	while(x != y)
	{
		if(x > y)
			x -= y;
		else
			y -= x;
	}
	return x;
}

bool zero_value(int a[], int n)
{
	for(int i=0; i<n; i++)
		if(a[i] == 0)
			return true;
	return false;
}

void gcd(int a[], int n)
{
	if(n<2 || zero_value(a,n) == 1)
		printf("don't have gcd.");
	else
	{
		int GCD;
		if(a[0] < 0)
			if(a[1] < 0)
				GCD = Gcd(-a[0], -a[1]);
			else
				GCD = Gcd(-a[0], a[1]);
		else
			if(a[1] < 0)
				GCD = Gcd(a[0], -a[1]);
			else
				GCD = Gcd(a[0], a[1]);
		for(int i=2; i<n; i++)
		{
			if(a[i] < 0)
				GCD = Gcd(GCD, -a[i]);
			else
				GCD = Gcd(GCD, a[i]);
		}
		printf("gcd is: %d", GCD);
	}
}

void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void increase(int a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]>a[j])
				swap(a[i], a[j]);
	outputArray(a,n);
}

void decrease(int a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]<a[j])
				swap(a[i], a[j]);
	outputArray(a,n);
}

void choose_sort(int &k, int a[], int n)
{
	printf("1. increase\n2. decrease\n");
	scanf("%d", &k);
	switch(k)
	{
		case 1: increase(a,n); break;
		case 2: decrease(a,n); break;
		default:
		{
			exit(0);
			break;
		}
	}
}

void selection(int a[], int n)
{
	int choose;
	printf("1. reverse\n2. math\n3. find and count\n4. greatest_common_divisor\n5. sort\n");
	scanf("%d", &choose);
	switch (choose)
	{
		case 1: 
		{
			reverse(a,n); 
			break;
		}
		case 2: 
		{
			int k;
			choose_math(k, a, n);
			break;
		}
		case 3: 
		{
			int k;
			choose_find_and_count(k, a, n);
			break;
		}
		case 4: 
		{
			gcd(a, n);
			break;
		}
		case 5: 
		{
			int k;
			choose_sort(k, a, n);
			break;
		}
		default:
		{
			exit(0);
			break;		
		}
	}
}

int main()
{
	int *arr;
	int n;
	scanf("%d", &n);
	arr = new int[n];
	inputArray(arr, n);
	selection(arr, n);
	//outputArray(arr, n)///;
	delete []arr;
}
