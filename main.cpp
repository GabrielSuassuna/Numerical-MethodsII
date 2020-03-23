#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
    Mat image;
    int rows;
    int columns;
    int option;

    image = imread("batista.png",CV_LOAD_IMAGE_GRAYSCALE);

    if(!image.data){
        cout << "Tem imagem não cara" << endl;
        return -1;
    }

    
    //Cria a Janela
    namedWindow("Janela Incrivel", cv::WINDOW_AUTOSIZE);

    //Função nativa no openCV para criar bordas
    //copyMakeBorder(src, output, top, bottom, left, right, Border_Type = Border_Constant, grayScale color)
    copyMakeBorder(image, image, 1,1,1,1, BORDER_CONSTANT,0);
    
    //Armazena número de linhas e colunas após adição da borda
    rows = image.rows;
    columns = image.cols;

    cout << "Para Box Blur digite 1 (Calculo com os pixel imediatamente a esquerda, direita, cima e abaixo)" << "\n";
    cout << "Para filtro gauseano digite 2 (Calculo com todos os pixels ao redor)" << "\n";
    cout << "Para Sharppen Effect, digite 3" << "\n";
    cout << "Para Edge Detection, digite 4" << "\n";
    cout << "Para máscara passada pelo Creto, digite 5" << "\n";
    cin >> option;

    if(option == 1){
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < columns; j++){
                image.at<uchar>(i,j) = ((int)image.at<uchar>(i-1,j) + (int)image.at<uchar>(i+1,j) + 
                                        (int)image.at<uchar>(i,j-1) + (int)image.at<uchar>(i,j+1))/4;
            }
        }
    }
    else if(option == 2){
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < columns; j++){
                image.at<uchar>(i,j) = ((int)image.at<uchar>(i-1,j+1) + ((int)image.at<uchar>(i,j+1)*2) + 
                                        (int)image.at<uchar>(i+1,j+1) + ((int)image.at<uchar>(i-1,j)*2) +
                                        ((int)image.at<uchar>(i,j)*4)+ ((int)image.at<uchar>(i+1,j)*2) + 
                                        (int)image.at<uchar>(i-1,j-1) + ((int)image.at<uchar>(i,j-1)*2)+
                                        (int)image.at<uchar>(i+1,j-1)) / 16;
            }
        }
    }
    //Sharppen Effect
    else if(option == 3){
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < columns; j++){
                image.at<uchar>(i,j) = (5*(int)image.at<uchar>(i,j) - (int)image.at<uchar>(i-1,j) - 
                                        (int)image.at<uchar>(i+1,j) - (int)image.at<uchar>(i,j-1) -
                                        (int)image.at<uchar>(i,j+1));
            }
        }
    }
    //Edge Detection
    else if(option == 4){
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < columns; j++){
                image.at<uchar>(i,j) = ((int)image.at<uchar>(i-1,j) - (int)image.at<uchar>(i,j-1) +
                                        (int)image.at<uchar>(i,j+1) -(int)image.at<uchar>(i+1,j));
            }
        }
    }
    else if(option ==5){
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < columns; j++){
                image.at<uchar>(i,j) = -2*( (1/(image.at<uchar>(i+1,j) - 2*image.at<uchar>(i,j) + image.at<uchar>(i-1,j))) +
                                            (1/(image.at<uchar>(i,j+1) - 2*image.at<uchar>(i,j) + image.at<uchar>(i,j-1))));
            }
        }
    }
    else{
        cout << "Opção inexistente, tente de novo!";
    }
    


    imshow("Janela Incrivel", image);

    waitKey();

    return 0;
}