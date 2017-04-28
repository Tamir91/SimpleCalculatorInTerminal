#include <stdio.h>

/*  
	This programm calculate sum, multiplication, difference, division for positive and negative real number.

	Autor Aleksey Yurovskiy
	ID 327153904
*/


enum status {SCAN_FRST_NUM, SCAN_SEC_NUM, OUT_OF_FRST_NUM};	/* Position in expression. */
enum oprtr {SUM, DIF, MULT, DIV};							/* Operators of expression. */

int myPow(int, int);
int calculate(void);


int calculate(void)
{	
	int c;
	double firN = 0, secN = 0;
	int changeSign = 1;          /* Multiplication by value 1 or -1 for positive or negative numbers. */
	int status = SCAN_FRST_NUM;	 /* Start with status scan first number.*/
	int oprtr    =-1;				 /* Operator not defined yet. */
	int isDuble  = 1;			 /* If isDouble = 1, number decimal, if isDouble = 0, number double. */
	int posPoint = 0;			 /* Position of point in readed number. */



	while ((c = getchar()) && c != '\n')
		switch(status)
		{	
			case SCAN_FRST_NUM:
				if(c == '-')
					{
						changeSign = -1;						
					}
				else if(c == '.')
					{
						isDuble = 0;					/* Changing flag isDouble.     */
					}					
				else if(c == ' ')						/* End reading first number.   */
					{	

						firN *= changeSign;				/* Change sign of first number */
						if(posPoint > 0) 				/* Insert point to his place.  */										
							firN = (firN / (myPow( 10, posPoint)));
						/*	printf("\nfirN ?? = %f\n", firN);*/
						status = OUT_OF_FRST_NUM;	

						isDuble    = 1;					/* Backing to first value.     */
						changeSign = 1;					/* Backing to first value.     */
						posPoint   = 0;					/* Backing to first value.     */
					}
				else 
					{	
						if(isDuble == 0)	 /* If number double starting to count digitles after point. */
							posPoint++;
						firN = firN * 10 + (c - '0');	/* Bildig first numbers		   */
					}
				putchar(c);
			break;

			case SCAN_SEC_NUM:
				if(c == '-')
					{
						putchar(c);
						changeSign = -1;
					}
				else if(c == '.')
					{	
						putchar (c);
						isDuble = 0;					/* Changing flag isDouble.*/
					}
				else if(c != ' ')						/* Reading second number. */
					{
						putchar(c);
						if(isDuble == 0)    /* If number double starting to count digitles after point. */
							posPoint++;
						secN = secN * 10 + (c - '0'); 	/* Bilding second numbers  	 */
					}
					
			break;

			case OUT_OF_FRST_NUM:
				if(c == '+') oprtr = SUM;
			    if(c == '-') oprtr = DIF;
			    if(c == '/') oprtr = DIV;
			    if(c == '*') oprtr = MULT;
			    if(c != ' ')
			    	{
			    		putchar( c );
			    		putchar(' ');			    		
			    		status = SCAN_SEC_NUM;
			    	}
			break;

		}/*End of switch*/
	/*End of While*/

	if(changeSign == -1)							/* Changing sign for second number.*/
		secN *= changeSign;
	if(posPoint > 0)
		secN = secN / (myPow(10, posPoint));		/* Insert point to his place for second number. */


	switch(oprtr)							  
	{
		case SUM:
			printf(" = %0.3f\n", firN + secN );
		break;

		case DIF:
			printf(" = %0.3f\n", firN - secN );
		break;

		case MULT:
			printf(" = %0.3f\n", firN * secN );
		break;

		case DIV:
			printf(" = %0.3f\n", firN / secN );
		break;
	}/*End of switch*/
	return 0;
}/*End of main*/


/* Thith method calculate num pow of base.
   Return int 								*/
int myPow(int base, int num)
{
	int count, val = 1;
	for(count = 1; count <= num; ++count)
		val = val * base;
	return val;
}
