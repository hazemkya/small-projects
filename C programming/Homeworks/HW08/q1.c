int account, amount;
char company[25];

/* 1) We want to write some information to the file "payments.dat": */
fptr = fopen("payments.dat", "w");
printf(fptr, "%d%s%d\n", account, company, amount);

/* 2) */
fopen("receive.dat", "r+");

/* 3) */
fptr = fopen("payments.dat", "r"); 
scanf(fptr, "%d%s%d\n", &account, company, &amount); 

/* 4) We want to open the file "tools.dat" and add some data: */
if ((fptr = fopen("tools.dat", "a"))){ /* statements */ } 
