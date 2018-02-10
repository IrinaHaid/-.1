#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
const int n = 10000, nn = 3000;
using namespace std;
#define LeftChild( i )  ( 2 * ( i ) + 1 )
typedef struct Node {
	int population, foundations;
	string city;
	struct Node *next;
}Node;
void AddNode(Node **tail, int p, int f, string c)
{
	Node *q;
	q = new Node;
	q->population = p;
	q->foundations = f;
	q->city = c;
	q->next = NULL;
	(*tail)->next = q;
	*tail = q;
}
void Clear(Node **head)
{
	Node *q = *head;
	while (q->next != NULL)
	{
		Node *t;
		t = q->next;
		q->next = q->next->next;
		delete t;
	}
}
void Show(Node **head)
{
	Node *temp;
	temp = (*head)->next;
	while (temp != NULL)
	{
		cout << temp->city << "  " << temp->population << "  " << temp->population << "  " << endl;
		temp = temp->next;
	}
	delete temp;
}
void show(int a[n], int n)
{
	int i;
	cout << "Sorted array\n";
	cout << "First 10 elements of the sorted array: ";
	for (i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Last 10 elements of the sorted array: ";
	for (i = n - 10; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//глупая сортировка
void stupidSort(int *A, int n)
{
	clock_t start = clock();
	int i = 0, tmp;
	while (i < n - 1)
	{
		if (A[i + 1] < A[i])
		{
			tmp = A[i];
			A[i] = A[i + 1];
			A[i + 1] = tmp;
			i = 0;
		}
		else i++;
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Sorting method stupidSort" << endl;
	printf("The time of the procedure: %f seconds (for n=3000 elements)\n", seconds);
}
//пирамидальная сортировка
int GT(int a, int b)
{
	return a > b;
}
void PERCDOWN(int A[], int i, int N)
{
	int Child, Tmp;
	for (Tmp = A[i]; LeftChild(i) < N; i = Child) {
		Child = LeftChild(i);
		if (Child != N - 1 && GT(A[Child + 1], A[Child]))
			Child++;
		if (Tmp<A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;
}
void SWAP(int * a, int * b)
{
	int           tmp = *a;
	*a = *b;
	*b = tmp;
}
void HEAPSORT(int A[n], int N)
{
	clock_t start = clock();
	int i;
	for (i = N / 2; i >= 0; i--)
		PERCDOWN(A, i, N);
	for (i = N - 1; i > 0; i--) {
		SWAP(&A[0], &A[i]);
		PERCDOWN(A, 0, i);
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Sorting method Heapsort" << endl;
	printf("The time of the procedure: %f seconds\n", seconds);
}
//еще одна сортировка
void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{
	clock_t start = clock();
	int i, k, n;
	k = sizeC;
	n = sizeAB;
	for (i = 0; i <= k; i++)
		cr[i] = 0;
	for (i = 0; i < n; i++)
		cr[ar[i]] += 1;
	for (i = 1; i < k + 1; i++)
		cr[i] += cr[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		br[cr[ar[i]] - 1] = ar[i];
		cr[ar[i]] -= 1;
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Sorting method radix" << endl;
	printf("The time of the procedure: %f seconds\n", seconds);
}
//сортировка слиянием
int LT(int a, int b)
{
	return a < b;
}
void MMERGE(int A[], int B[], size_t l, size_t m, size_t r)
{
	size_t          i = l;
	size_t          j = m + 1;
	size_t          k = l;
	while ((i <= m) && (j <= r)) {
		if (LT(A[i], A[j]))
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	while (i <= m) {
		B[k++] = A[i++];
	}
	while (j <= r) {
		B[k++] = A[j++];
	}
	for (k = l; k <= r; k++) {
		A[k] = B[k];
	}
}
void MSORT(int A[], int B[], size_t l, size_t  r)
{
	size_t m;
	if (l < r) {
		m = ((l + r) >> 1);
		MSORT(A, B, l, m);
		MSORT(A, B, m + 1, r);
		MMERGE(A, B, l, m, r);
	}
}
int main()
{
	int i = 0, p, f;
	string c;
	Node *head, *tail;
	head = new Node;
	tail = new Node;
	head->next = NULL;
	tail->next = head;
	tail = head;
	ifstream file;
	file.open("L2.txt");
	while (!file.eof()/*i != 5*/)
	{
//		i++;
	//	cin >> c >> p >> f;
		file >> c>>p>>f;
		AddNode(&tail, p, f, c);
		cout << c << " " << p << " " << f << " " << endl;
	}
	/* size_t l=0,r=n;
	int  i, a[n], b[n], c[10],d[n],e[n],g[nn];
	for (i = 0; i < n; i++)
	{
	a[i] = 0 + rand() % 9;
	d[i] = a[i];
	e[i]=a[i];
	g[i]=a[i];
	}
	for (i = 0; i < nn; i++)
	{
	g[i] = 0 + rand() % 9;
	}
	cout << "First 10 elements of the array: ";
	for (i = 0; i < 10; i++)
	cout << a[i] << " ";
	cout << endl;
	radix(a, b, c, 10, n);
	clock_t start = clock();
	MSORT(d,b,l,r);
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Sorting method Merge sort" << endl;
	printf("The time of the procedure: %f seconds\n", seconds);
	HEAPSORT(e,n);
	stupidSort(g,nn);*/
	Show(&head);
	Clear(&head);
	file.close();
	system("pause");
	return 0;
}
