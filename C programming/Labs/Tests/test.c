int main(int argc, char const *argv[])
{
	int i, c=4, a=2048, b=a;
	for (i = 0; i <= c; ++i)
	{
		printf("a=%d\t", a= a % 10);
		printf("b=%d\n", b= b / 10);

	}
	return 0;
}