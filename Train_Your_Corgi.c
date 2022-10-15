#include<stdio.h>
typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28
/*當小智餵食柯基時，會增加 STRENGTH_EAT 量的體力值，但會降低 OBEDIENCE_EAT 的服從度
當柯基接受訓練時，會增加 OBEDIENCE_TRAIN 量的服從度，並減少 STRENGTH_TRAIN 的體力值
當服從度不小於 LEARN_OBEDIENCE，並且體力值不大於 LEARN_STRENGTH 時，就可以成功訓練一個指令。這時候柯基的體力值不變，但服從度會變為 INIT_OBEDIENCE。
小智規劃了一系列的訓練活動，請你幫小智評估這套訓練活動最後能不能讓柯基學會 5 個指令。
一串字串，由 '\n' 結尾，其中
當輸入字元為 'e' : 餵食。
當輸入字元為 't' : 訓練。
當輸入字元為 '\n' 時：結束。
*/

int main(void)
{
    //initizal the strength and obedience
    Strength strength =INIT_STRENGTH;
    Obedience obedience =INIT_OBEDIENCE;
     int n=0;//成功的指令數
    //get the input
   while(1){
    int cmd =getchar();//讀取一個字元
   
    if(strength<=LEARN_STRENGTH&&obedience>=LEARN_OBEDIENCE)//當服從度不小於 LEARN_OBEDIENCE，並且體力值不大於 LEARN_STRENGTH 時，就可以成功訓練一個指令。
    {
        n+=1;//成功一次了
        obedience=INIT_OBEDIENCE;//這時候柯基的體力值不變，但服從度會變為 INIT_OBEDIENCE。
        //printf("hahaah\n");
    }
    
    //eating 當小智餵食柯基時，會增加 STRENGTH_EAT 量的體力值，但會降低 OBEDIENCE_EAT 的服從度
     if(cmd=='e')
        {
        strength+=STRENGTH_EAT;
        obedience-=OBEDIENCE_EAT;
        }
        else if(cmd=='t')//while traing 當柯基接受訓練時，會增加 OBEDIENCE_TRAIN 量的服從度，並減少 STRENGTH_TRAIN 的體力值
        {
        strength-=STRENGTH_TRAIN;
        obedience+=OBEDIENCE_TRAIN;
        }
        else if (cmd=='\n')//the input end and it's time to see the ans（結算）
        {
            if(n==5)
            {
                printf("Yes\n");
                return 0;

            }
            else
            {
                printf("No\n");
                return 0;
            }
        }
   }
    

   
   

    //return 0;
}