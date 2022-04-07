int accountNum; float currentBalance, dollarAmount; char name[50];
1:
	FILE* ofPtr = fopen("oldmast.dat", "r");
2:
	FILE* tfPtr = fopen("trans.dat", "r");
3:
	FILE* nfPtr = fopen("newmat.dat", "w");
4:
	fscanf(ofPtr, "%d%s%f",&accountNum, name, &currentBalance);
5:
	fscanf(tfPtr, "%d%f",&accountNum, &dollarAmount);
6:
	fprintf(nfPtr, "%d%s%f",accountNum, name, currentBalance);