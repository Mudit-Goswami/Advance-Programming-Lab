import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

class KnapSack2
{

public static void knapsack (int n,double weight[], double profit[],double capacity)
{
	double x[]=new double[200];
    double tp=0;
    int i,j;
    double u=capacity;
    for(i=0;i<n;i++)
        x[i]=0;
    for(i=0;i<n;i++)
    {

        if(weight[i]>u)
            x[i]=0;
        else
        {
            x[i]=1;
            tp=tp+profit[i];
            u=u-weight[i];

        }
    }
 
    System.out.println("The result vector is:");
    for (i=0;i<n;i++)
        System.out.println(x[i]);
    System.out.println("Maximum profit is:"+tp);
}

public static void main(String args[])throws FileNotFoundException
{
	long starttime = System.currentTimeMillis();
   
    int num=0;
    Double temp;
    
	double weight[]= new double[200];
	double profit[]= new double[200];
	double ratio[]= new double[200];
	BufferedReader br1 = new BufferedReader(new FileReader("02_c.txt"));
        Scanner sc = new Scanner(br1);
		String st3=sc.next().trim();
		double capacity=Double.parseDouble(st3);
	BufferedReader br2 = new BufferedReader(new FileReader("02_p.txt"));
	Scanner sc1 = new Scanner(br2);
	BufferedReader br3 = new BufferedReader(new FileReader("02_w.txt"));
	Scanner sc2 = new Scanner(br3);  
    
	while(sc1.hasNext())
	{
		String st1=sc1.next().trim();
		profit[num]=Double.parseDouble(st1);
		String st2=sc2.next().trim();
		weight[num]=Double.parseDouble(st2);
		ratio[num]=profit[num]/weight[num];
		num++;
	}
    
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;

            }
        }
    }
for(int i=0;i<num;i++)
{
	System.out.print("  "+profit[i]);
	
	
}	
System.out.println();
for(int i=0;i<num;i++)
{
	System.out.print("  "+weight[i]);
	
	
}
System.out.println();
for(int i=0;i<num;i++)
{
	System.out.print("  "+ratio[i]);
	
	
}
System.out.println();
        knapsack(num,weight,profit,capacity);
		long endtime = System.currentTimeMillis();
       
		System.out.println("The Execution Time is"+(endtime-starttime));
}
}
