import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.stream.Stream;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TreePartition solver = new TreePartition();
        solver.solve(1, in, out);
        out.close();
    }

    static class TreePartition {
        int mod = 998244353;
        List<Integer>[] child;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] p = new int[n];
            child = LUtils.genArrayList(n);
            for (int i = 1; i < n; i++) {
                p[i] = in.nextInt() - 1;
                child[p[i]].add(i);
            }
            int[][] dp = new int[n][3];
            // 0 -> this node is in no partition
            // 1 -> this node is in some partition, but needs to be connected above
            // 2 -> this node is in some partition, doesn't need to connect
            for (int i = n - 1; i >= 0; i--) {
                if (child[i].size() == 0) {
                    dp[i][2] = 1;
                    continue;
                }

                dp[i][0] = 1;
                for (int x : child[i]) {
                    dp[i][2] = (int) ((1L * (dp[i][1] + dp[i][2]) * (dp[x][1] + dp[x][2]) + 1L * dp[i][2] * (dp[x][0] + dp[x][2])) % mod);
                    dp[i][1] = (int) ((1l * dp[i][0] * (dp[x][1] + dp[x][2]) + 1L * dp[i][1] * (dp[x][0] + dp[x][2])) % mod);
                    dp[i][0] = (int) (1L * dp[i][0] * (dp[x][0] + dp[x][2]) % mod);
                }
            }
            out.println((dp[0][0] + dp[0][2]) % mod);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}

