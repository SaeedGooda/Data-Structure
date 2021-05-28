#include "matrixCalculator.h"
#include "matrix.h"



 MatrixCalculator::MatrixCalculator(){
cout<<"\n\n\t\t\t\ ****** Welcome to Matrix Calculator   *******\n ";
cout<<"Enter type of Matrices: \n" << "\t\t(1) int \n" <<"\t\t(2) float \n" << "\t\t(3) double \n"<<endl;
cin>> type;
menu();
cin>>choice;
MatCal();

}

void MatrixCalculator::MatCal(){
    int r,c;
    int exit=0;

while (exit==0){
   if (type == 1){
            cout<<"Enter rows & columns of First Matrix"<<endl;
            cin>>r>>c;
            Matrix <int> mat1(r,c,0);
            mat1.MatrixElements();                                // inserting mat 1 elements
            cout<<"Enter rows & columns of Second Matrix"<<endl;
            cin>>r>>c;
            Matrix <int> mat2(r,c,0);
            mat2.MatrixElements();                                 // inserting mat 1 elements
            Matrix <int> result (r,c,0);
        if (choice==1){
                    result=mat1+mat2;
                    cout<<"sum: \n";
                    result.display();
        }
        else if (choice ==2){
                    result=mat1-mat2;
                    cout<<"diff: \n";
                    result.display();
        }
          else if (choice ==3){
                if (mat1.get_col()==mat2.get_row()){
                    result=mat1*mat2;
                    cout<<"product: \n";
                    result.display();}
                    else
                        cout<<"\n\tCan not be multiplied"<<endl;
        }
         else if (choice ==4){
                    cout<<"mat (1) transpose : \n";
                    result=mat1.transpose();
                    result.display();
                    cout<<"mat (2) transpose : \n";
                    result=mat2.transpose();
                    result.display();
        }
        else if (choice ==5){
            cout<<"Goodbye!"<<endl;
            exit=1;

        }
        else
            cout<<"error"<<endl;

   }

    else if (type == 2 ){
            cout<<"Enter rows & columns of First Matrix"<<endl;
            cin>>r>>c;
            Matrix <float> mat1(r,c,0);
            mat1.MatrixElements();                                // inserting mat 1 elements
            cout<<"Enter rows & columns of Second Matrix"<<endl;
            cin>>r>>c;
            Matrix <float> mat2(r,c,0);
            mat2.MatrixElements();                                 // inserting mat 1 elements
            Matrix <float> result (r,c,0);
        if (choice==1){
                    result=mat1+mat2;
                    cout<<"sum: \n";
                    result.display();
        }
        else if (choice ==2){
                    result=mat1-mat2;
                    cout<<"diff: \n";
                    result.display();
        }
          else if (choice ==3){
                if (mat1.get_col()==mat2.get_row()){
                    result=mat1*mat2;
                    cout<<"product: \n";
                    result.display();}
                    else
                        cout<<"\n\tCan not be multiplied"<<endl;
          }
         else if (choice ==4){
                    cout<<"mat (1) transpose : \n";
                    result=mat1.transpose();
                    result.display();
                    cout<<"mat (2) transpose : \n";
                    result=mat2.transpose();
                    result.display();
        }
        else if (choice ==5){
            cout<<"Goodbye!"<<endl;
            exit=1;

        }
        else
            cout<<"error"<<endl;


    }
    else if (type ==3){
          cout<<"Enter rows & columns of First Matrix"<<endl;
            cin>>r>>c;
            Matrix <double> mat1(r,c,0);
            mat1.MatrixElements();                                // inserting mat 1 elements
            cout<<"Enter rows & columns of Second Matrix"<<endl;
            cin>>r>>c;
            Matrix <double> mat2(r,c,0);
            mat2.MatrixElements();                                 // inserting mat 1 elements
            Matrix <double> result (r,c,0);
        if (choice==1){
                    result=mat1+mat2;
                    cout<<"sum: \n";
                    result.display();
        }
        else if (choice ==2){
                    result=mat1-mat2;
                    cout<<"diff: \n";
                    result.display();
        }
        else if (choice ==3){
                if (mat1.get_col()==mat2.get_row()){
                    result=mat1*mat2;
                    cout<<"product: \n";
                    result.display();}
                    else
                        cout<<"\n\tCan not be multiplied"<<endl;
        }
         else if (choice ==4){
                    cout<<"mat (1) transpose : \n";
                    result=mat1.transpose();
                    result.display();
                    cout<<"mat (2) transpose : \n";
                    result=mat2.transpose();
                    result.display();
        }
        else if (choice ==5){
            cout<<"Goodbye!"<<endl;
            exit=1;

        }
        else
            cout<<"error"<<endl;

    }


}
}

void MatrixCalculator::menu(){
cout<<  "\t\t1- Perform Matrix Addition\n"<<
        "\t\t2- Perform Matrix Subtraction\n"<<
        "\t\t3- Perform Matrix Multiplication\n"<<
        "\t\t4- Matrix Transpose\n"<<
        "\t\t5-exit\n";

}


