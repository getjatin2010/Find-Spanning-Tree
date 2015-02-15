#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>
#endif
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
float xCoo;
int i ;
int costInt[20];
int size1 = 600;
int size2= size1/2;
int go;
int t;
int countForTotalNodesUsed = 0;
int countForTotalNodes = 0 ;
float arr[100][2],temp[1][2],usedNode[300][4],checkNotSame[1][2],edge[100][100];
int cost[100][100];
float yCoo;
int makeEdge = 0;
int j;
int texta = 0;
int flag3,flag2 = 0,flag4 = 0;
int countTotalEdges = 0;
char character2,character1,printvalue[] = "Cost:";
int valueInputFlag;
int texta2;
int sum;
int costCharacterNumber = -1;
int node1OfEdge,node2OfEdge;
char costCharacterRem[100][20];
float avgx,avgy;
float buttonVertexX1;
float buttonVertexY1;
float buttonVertexX2;
float buttonVertexY2;
int solution[1000][2];
char costCharacters[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
char minCostCharacter[20] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
char print[] = "Minimum Cost:";
char print2[] = "No Spanning Tree";
char tradeMark[] = "Jatin Arora: www.thinkncode.wordpress.com";
int mini,mincost,mincost1;
int r,s;
int near1[200];
int index;
int u;
int k;
int mincostarray[1000];
int l;
int tex2;
int solutionDone = 0;
int m;
int te;
 void   draw()
        {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        int texq = 0;
                 while( tradeMark[texq]!='\0')
            {
                glColor3f(1.0f,1.0f,1.0f);
                glPushMatrix();
            glRasterPos3d(-.9+texq*.035,-0.96,0.0);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,tradeMark[texq]);
            texq++;
            glPopMatrix();
            }


        j = 0;
        while(j!=countTotalEdges)
        {
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_LINES);
    glVertex3d(usedNode[j][0],usedNode[j][1],1.0f);
    glVertex3d(usedNode[j][2],usedNode[j][3],1.0f);
    glEnd();
      t = 0;

      avgx = (usedNode[j][0]+usedNode[j][2])/2;
          avgy = (usedNode[j][1]+usedNode[j][3])/2;
          if ( costCharacterRem[j][0] != '0' && costCharacterRem[j][0] !='\0' )
        {
             glRasterPos3d(avgx,avgy+.02,0.0f);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,costCharacterRem[j][t]);
            t++;
        }
      while(costCharacterRem[j][t]!= '\0' )
      {
            glRasterPos3d(avgx+(t*.03),avgy+.02,0.0f);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,costCharacterRem[j][t]);
            t++;
        }
        j++;
        }
        i = 0 ;
        character1 = '0';
        character2 = '0';
        while( i!=countForTotalNodes)
        {
            // flag 4 remembers the firstNode and makes it yellow
            // flag 3 checks whether the right clicked member is a node or not!
            flag4 = 0;
            j = 0;
            flag3 = 0;
            while( j != countForTotalNodesUsed)
            {
                if( ( arr[i][0]== usedNode[j][0] && arr[i][1]==usedNode[j][1] )|| ( arr[i][0]== usedNode[j][2] && arr[i][1]==usedNode[j][3] ))
                {
                    flag3 = 1;
                    if ( arr[i][0]== usedNode[countTotalEdges][0] && arr[i][1]== usedNode[countTotalEdges][1] )
                        flag4 = 1;
                    break;
                }
                j++;
            }
            if( flag3 == 1 && flag4 == 1)
            glColor3f(1.0f,1.0f,0.0f);
            else if ( flag3 == 1 && flag4 == 0)
                glColor3f(0.0f,1.0f,0.0f);
            else
                glColor3f(1.0f,0.0f,0.0f);
             glPushMatrix();
        glTranslatef(arr[i][0],arr[i][1],0.0f);
            glutSolidSphere(.025f,20,20);

            //sprintf(number,"%d",10);
                //if( character)
                glRasterPos3d(0.01f,0.018f,0.0f);
            if ( character1 != '0' )
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,character1);
            glRasterPos3d(0.04f,0.018f,0.0f);
        }
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,character2);
            i++;
            character2++;
            if( i%10 == 0 && i!=0)
            {
                character1++;
                character2 = '0';
            }
            glPopMatrix();

        }


    if ( valueInputFlag == 1)
            {
            while( printvalue[texta]!='\0')
            {
                glPushMatrix();
            glRasterPos3d(.5+texta*.035,0.9,0);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,printvalue[texta]);
            texta++;
            glPopMatrix();
            }
            texta2 = 0;
            while(costCharacters[texta2] != '\0' )
            {
                glPushMatrix();
            glRasterPos3d(.5+texta*.035,0.9,0);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,costCharacters[texta2]);
            texta2++;
            texta++;
            glPopMatrix();

            }
            texta = 0;
            }
            if ( solutionDone == 1)
            {
                int tex = 0;
               for( te = 0 ; te<countForTotalNodes-1;te++)
    {
     glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex3d(arr[solution[te][0]][0],arr[solution[te][0]][1],1.0f);
    glVertex3d(arr[solution[te][1]][0],arr[solution[te][1]][1],1.0f);
    glEnd();
    }
     while( print[tex]!='\0')
            {
                glPushMatrix();
            glRasterPos3d(.2+tex*.035,0.9,0);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,print[tex]);
            tex++;
            glPopMatrix();
            }
            tex2 = 0;
            while(minCostCharacter[tex2] != '\0' )
            {
            glPushMatrix();
            glRasterPos3d(.2+tex*.035,0.9,0);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,minCostCharacter[tex2]);
            tex2++;
            tex++;
            glPopMatrix();
            }
            tex = 0;
            }
            else if(solutionDone == 2)
            {
                int tex = 0;
                 while( print2[tex]!='\0')
            {
                glPushMatrix();
            glRasterPos3d(0.0+tex*.035,0.9,0.0);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,print2[tex]);
            tex++;
            glPopMatrix();
            }

            }

         buttonVertexX1 = (float)500/size2-1;
         buttonVertexY1 = 1- (float)500/size2;
         buttonVertexX2 = (float)580/size2-1;
         buttonVertexY2 = 1- (float)550/size2;
         glColor3f(1.0f,0.0f,0.0f);
         if (solutionDone == 1)
         glColor3f(1.0f,0.0f,1.0f);
            glPushMatrix();
            glBegin(GL_QUADS);
            glTranslatef(0.0,0.0,0.0);
            glVertex3f( buttonVertexX1,buttonVertexY1,0.0f);
            glVertex3f( buttonVertexX2,buttonVertexY1,0.0f);
            glVertex3f( buttonVertexX2,buttonVertexY2,0.0f);
            glVertex3f( buttonVertexX1,buttonVertexY2,0.0f);
            glEnd();
            glPopMatrix();


                    glutSwapBuffers();
}
    void findSpanningTree()
{
    solutionDone = 1;
    mini = cost[0][0];
    k = 0;
    l = 0;
    for(r = 0;r<countForTotalNodes;r++ )
    {
        for(s = 0;s<countForTotalNodes;s++)
        {
            if(cost[r][s]<mini)
            {
                mini = cost[r][s];
                k = r;
                l = s;
            }

        }
    }
    mincost = cost[k][l];
    solution[0][0] = k;
    solution[0][1] = l;

    for( u = 0;u<countForTotalNodes;u++)
    {
        if(cost[u][l]<cost[u][k])
        {
            near1[u] = l;
        }
        else near1[u] = k;
    }
        near1[k] = -1;
        near1[l] = -1;
    for ( u = 1 ; u<countForTotalNodes-1;u++)
    {

            mini = 100000000000000;
            for( int z = 0 ; z<countForTotalNodes;z++)
            {
                if ( near1[z] != -1 )
                {
                if( cost[z][near1[z]]<mini)
                {
                    mini = cost[z][near1[z]];
                    index = z;
                }
                }
            }

        solution[u][0] = index;
        solution[u][1] = near1[index];
        mincost = cost[index][near1[index]]+mincost;
        near1[index] = -1;
        for( m = 0;m<countForTotalNodes;m++)
        {
            if(near1[m]!= -1)
            {
                if(cost[m][near1[m]]>cost[m][index])
                    near1[m] = index;

            }
        }

    }
    printf("%d",mincost);
    mincost1  = mincost ;
}

void makeMinCostCharacter()
{
    if( mincost1>=100000000)
    {
        solutionDone = 2;
    }

    int texa = -1;
    int temprary;
    int texta = -1;
    while( mincost1 != 0)
    {
        texta++;
        temprary = mincost1%10;
        mincost1 = mincost1/10;
        mincostarray[texta] = temprary;
    }
    while(texta!=-1)
    {
        temprary = mincostarray[texta];
    texta--;
    texa++;
        switch(temprary)
        {
            case  0:
            minCostCharacter[texa] = '0';
            break;
            case  1:
            minCostCharacter[texa] = '1';
            break;
            case  2:
            minCostCharacter[texa] = '2';
            break;
            case  3:
            minCostCharacter[texa] = '3';
            break;
            case  4:
            minCostCharacter[texa] = '4';
            break;
            case  5:
            minCostCharacter[texa] = '5';
            break;
            case  6:
            minCostCharacter[texa] = '6';
            break;
            case  7:
            minCostCharacter[texa] = '7';
            break;
            case  8:
            minCostCharacter[texa] = '8';
            break;
            case  9:
            minCostCharacter[texa] = '9';
            break;

        }


    }


}

void renderScene(int button,int state,int x,int y)
{
    if(solutionDone == 0)
    {
    if( x>500 && x<580 && y>500 && y<550 && state == GLUT_DOWN)
    {
        findSpanningTree();
        makeMinCostCharacter();
        draw();
    }
 else
 {
  if ( valueInputFlag == 0)
  {
         xCoo = (float)x/size2-1;
         yCoo = 1-(float)y/size2;

    if( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
    {
          i = 0;
         go = 0;
    while( i != countForTotalNodes)
    {
        if (xCoo < (arr[i][0] + 0.05) && xCoo>(arr[i][0]-0.05)&&yCoo > arr[i][1]-0.05 && yCoo<(arr[i][1]+0.05)  )
        {
            go = 1;
            break;
        }
        i++;
    }
    if (go==0)
    {
        arr[countForTotalNodes][0] = xCoo;
        arr[countForTotalNodes][1] = yCoo;
        countForTotalNodes++;

    }
    draw();
    }




    //flag2 checks is it first node of the edge or second node of the edge
    //ValueInputFlag
    else if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
            temp[0][0] = (float)x/size2-1;
            temp[0][1] = 1-(float)y/size2;
            for ( i = 0; i < countForTotalNodes; i++ )
            {
                if ( temp[0][0] < (arr[i][0] + 0.025) && temp[0][0]>(arr[i][0]-0.025)&&temp[0][1] > arr[i][1]-0.025 && temp[0][1]<(arr[i][1]+0.025)  )
                {
                    if( checkNotSame[0][0]!=arr[i][0] && checkNotSame[0][1]!=arr[i][1] || flag2 == 0)
                    {
                    checkNotSame[0][0] = arr[i][0];
                    checkNotSame[0][1] = arr[i][1];
                    if ( flag2 == 0 )
                    {
                    usedNode[countTotalEdges][0] = arr[i][0];
                    usedNode[countTotalEdges][1] = arr[i][1];
                    node1OfEdge = i;
                    flag2 = 1;
                    countForTotalNodesUsed++;
                    draw();
                    }
                    else if ( flag2 == 1)
                    {
                        usedNode[countTotalEdges][2] = arr[i][0];
                        usedNode[countTotalEdges][3] = arr[i][1];
                        countTotalEdges++;
                        countForTotalNodesUsed++;
                        node2OfEdge = i;
                        edge[node1OfEdge][node2OfEdge] = 1;
                         edge[node2OfEdge][node1OfEdge] = 1;
                        valueInputFlag=1;
                        flag2 = 0;
                   draw();
                    }
                    }
                }

             }
    }
  }
 }

 }
}
void input(unsigned char key ,int x,int y)
{
    if (valueInputFlag==1)
    {
        switch(key)
        {
        case  48:
            costCharacterNumber++;
            costCharacters[costCharacterNumber] = '0';
            costCharacterRem[countTotalEdges-1][costCharacterNumber] = '0';
            costInt[costCharacterNumber] = 0;
            draw();
            break;
        case  49:
            costCharacterNumber++;
            costCharacters[costCharacterNumber] = '1';
            costCharacterRem[countTotalEdges-1][costCharacterNumber] = '1';
            costInt[costCharacterNumber] = 1;
            draw();
            break;
        case  50:
            costCharacterNumber++;
            costCharacters[costCharacterNumber] = '2';
            costCharacterRem[countTotalEdges-1][costCharacterNumber] = '2';
            costInt[costCharacterNumber] = 2;
            draw();
            break;
            case 51:
            costCharacterNumber++;
            costCharacters[costCharacterNumber] = '3';
            costCharacterRem[countTotalEdges-1][costCharacterNumber] = '3';
            costInt[costCharacterNumber] = 3;
            draw();
            break;
        case  52:
            costCharacterNumber++;
            costCharacters[costCharacterNumber] = '4';
            costCharacterRem[countTotalEdges-1][costCharacterNumber] = '4';
            costInt[costCharacterNumber] = 4;
            draw();
            break;
        case  53:
            costCharacterNumber++;
            costCharacters[costCharacterNumber] = '5';
            costCharacterRem[countTotalEdges-1][costCharacterNumber] = '5';
            costInt[costCharacterNumber] = 5;
            draw();
            break;
        case  54:
            costCharacterNumber++;
            costCharacters[costCharacterNumber] = '6';
            costCharacterRem[countTotalEdges-1][costCharacterNumber] = '6';
            costInt[costCharacterNumber] = 6;
            draw();
            break;
        case  55:
            costCharacterNumber++;
            costCharacters[costCharacterNumber] = '7';
            costCharacterRem[countTotalEdges-1][costCharacterNumber] = '7';
            costInt[costCharacterNumber] = 7;
            draw();
            break;
        case  56:
            costCharacterNumber++;
            costCharacters[costCharacterNumber] = '8';
            costCharacterRem[countTotalEdges-1][costCharacterNumber] = '8';
            costInt[costCharacterNumber] = 8;
            draw();
            break;
        case  57:
            costCharacterNumber++;
            costCharacters[costCharacterNumber] = '9';
            costCharacterRem[countTotalEdges-1][costCharacterNumber] = '9';
            costInt[costCharacterNumber] = 9;
            draw();
            break;
        case 13:

         for(int y=0; y<20;y++)
         {
         costCharacters[y]='\0';
         }
         sum = 0;
         for( int z=0;z<=costCharacterNumber;z++)
         {
             sum = pow(10,costCharacterNumber-z)*costInt[z]+sum;
         }
         cost[node1OfEdge][node2OfEdge] = sum;
         cost[node2OfEdge][node1OfEdge] = sum;
         costCharacterNumber = -1;
         valueInputFlag = 0 ;
            draw();
            break;



        }
    }

}



int main(int argc, char **argv) {

	// init GLUT and create Window
	printf("\t\tINSTRUCTIONS\n\n1.Right Click to create a Node!\n2.Left Click to Select a Node\n3.Press Enter to input the Cost\n4. Press the Red Button to get Spanning Tree\n\n(If not able to create any edge please Re-run the application)\n\nFor more details visit : www.thinkncode.wordpress.com");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(300,50);
	glutInitWindowSize(size1,size1);
	glutDisplayFunc(draw);
	glutCreateWindow("Spanning Tree");
	for( int q = 0 ; q<100;q++)
    {
        for( int l = 0 ; l<100;l++)
        {
            cost[q][l]=100000000;

        }
    }

	// register callbacks
	//glutDisplayFunc(renderScene);
	draw();
glutMouseFunc(renderScene);
glutKeyboardFunc(input);
	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
