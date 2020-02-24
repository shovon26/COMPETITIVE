import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class EulerBernoulliTriangle {

    static Scanner input=new Scanner(System.in);


    public static void main(String[] args) throws IOException {

        EulerBernoulliTriangle ob = new EulerBernoulliTriangle();
        int n;
        n = input.nextInt();

        //   System.out.println(facto(n));
        System.out.println();

        ob.Print_Number(n);
    }

    ////Calculate factorial for a large number

    private static BigInteger facto(int n) {
        BigInteger res = BigInteger.ONE;
        for(int i=2;i<=n;i++){
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }


    public static BigInteger[][] GetMatrix(int n) {
        BigInteger[][] Arr = new BigInteger[1000][1000];

        /////////Initialize the biginteger array to 0
        for(int i=0;i<Arr.length;i++){
            for(int j=0;j<Arr[i].length;j++){
                Arr[i][j] = BigInteger.ZERO;
            }
        }

        Arr[1][1] = BigInteger.valueOf(1);
        Arr[2][1] = BigInteger.valueOf(0);
        Arr[2][2] = BigInteger.valueOf(1);

        Arr[0][0]=BigInteger.valueOf(0);
        Arr[n+1][n+1]=BigInteger.valueOf(0);

        for (int i = 3; i <= n; i++) {
            if (i % 2 == 1) {
                for (int j = i, x = 1; j >= 1; j--, x++) {
                    if (x == 1) Arr[i][j] = BigInteger.valueOf(0);
                    else {
                        BigInteger init = BigInteger.ZERO;

                        /*String z = Arr[i][j+1].toString();
                        BigInteger val1 = init.add(new BigInteger(z));
                        String ss = Arr[i-1][j].toString();
                        BigInteger val2 = val1.add(new BigInteger(ss));
                        String ans = val2.toString();
                        Arr[i][j] = new BigInteger(ans);*/

                        BigInteger val1 = Arr[i][j+1];
                        BigInteger val2 = val1.add(Arr[i-1][j]);
                        Arr[i][j] = val2;
                    }
                }
            }
            else{
                for(int j=1,x=1;j<=n;j++,x++){
                    if(x==1) Arr[i][j] = BigInteger.valueOf(0);
                    else{
                        BigInteger val1 = Arr[i][j-1];
                        BigInteger val2 = val1.add(Arr[i-1][j-1]);
                        Arr[i][j] = val2;
                    }
                }
            }
        }
        return Arr;
    }

    public void Print_Number(int n){

        BigInteger[][] Arr = new BigInteger[10000][10000];

        Arr = GetMatrix(n);

        System.out.println("The Eulers numbers: ");
        for(int i=1;i<=n;i++){
            if(i%2==1)
                System.out.println(Arr[i][1]);
        }
        int k=n/2;
        if(n%2==1)k++;
        System.out.println("That's "+k+" Eulers Numbers");
        System.out.println();
        System.out.println();


        System.out.println("The Bernoulli numbers: ");
        for(int i=1;i<=n;i++){
            if(i%2==0 || i==1)
                System.out.println(Arr[i][i]);
        }
        if(n%2==0)k++;
        System.out.println("That's "+k+" Bernoulli Numbers");
        System.out.println();
    }
}
