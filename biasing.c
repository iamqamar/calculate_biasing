#include<stdio.h>
void main(){
    float iB, iC, iE;
    float rB, rC, rE;
    float vB, vC, vE;
    float vCC, beta;
    float vBE = 0.7, vCE;
    float vth, rth;
    float r1, r2;

    int choice;
    printf("Select a BJT biasing\n");
    printf("1. Fixed Biasing\n");
    printf("2. Emitter Stabalized Biasing\n");
    printf("3. Voltage Divider Biasing\n");
    scanf("%d",&choice);

    if(choice == 1){
        rE = 0;
        printf("Enter the value of Vcc: ");
        scanf("%f", &vCC);
        printf("Enter the value of Rb and Rc: ");
        scanf("%f %f", &rB, &rC);
        printf("Enter the value of beta: ");
        scanf("%f",&beta);
        
        iB = (vCC - vBE) / (rB + (beta++ * rE));
    }
    else if(choice == 2){
        printf("Enter the value of Vcc: ");
        scanf("%f", &vCC);
        printf("Enter the value of Rb, Rc and Re: ");
        scanf("%f %f %f", &rB, &rC, &rE);
        printf("Enter the value of beta: ");
        scanf("%f",&beta);

        iB = (vCC - vBE) / (rB + (beta++ * rE));
    }
    else if(choice == 3){
        printf("Enter the value of Vcc: ");
        scanf("%f", &vCC);
        printf("Enter the value of Rc and Re: ");
        scanf("%f %f", &rC, &rE);
        printf("Enter the value of R1 and R2: ");
        scanf("%f %f",&r1,&r2);
        printf("Enter the value of beta: ");
        scanf("%f",&beta);

        vth = (r2/(r1+r2))*vCC;
        rth = (r1*r2)/(r1+r2);

        iB = (vth - vBE) / (rth + (beta++ * rE));

        printf("\n Values of Vth and Rth are: %.3f and %.3f respectively.\n", vth, rth);
    }
    
    iC = beta * iB;
    iE = iC + iB;

    vCE = vCC + (iC * (rC+rE));
    vE = iE * iB;
    vB = vE + vBE;
    vC = vE + vCE;

    printf("\nValues of Ib, Ic and Ie are: %.3f, %.3f and %.3f respectively.\n",iB,iC,iE);
    printf("Values of Vb, Vc and Ve are: %.3f, %.3f and %.3f respectively.\n",vB,vC,vE);
    printf("Value of Vce is: %.3f\n", vCE);
}
