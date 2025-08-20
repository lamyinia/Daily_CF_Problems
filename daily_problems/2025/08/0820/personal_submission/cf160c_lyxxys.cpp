public class Main {
    static long n, k;
    static int[] As;

    public static void solve(){
        n = sc.nextLong();
        k = sc.nextLong();
        As = new int[(int) n];
        for (int i = 0; i < n; ++ i){
            As[i] = sc.nextInt();
        }

        Arrays.sort(As);

        for (int i = 0, j; i < n; ++ i){
            j = i;
            long count = 1;
            while (j+1 < n && As[j+1] == As[j]){
                j += 1;
                count += 1;
            }
            if (n*count >= k){
                out.println(As[i] + " " + As[(int) ((k-1)/count)]);
                return;
            }
            k -= n * count;
            i = j;
        }

        out.println(-1);
    }

    public static void main(String[] args) throws IOException{
        int T_case = 1;
        if (multiCase) T_case = sc.nextInt();
        while (T_case > 0){
            solve();
            T_case -= 1;
        }
        out.close( );
    }
}
