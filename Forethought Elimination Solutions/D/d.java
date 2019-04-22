import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

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
        FrogJumping solver = new FrogJumping();
        solver.solve(1, in, out);
        out.close();
    }

    static class FrogJumping {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int m = in.nextInt(), a = in.nextInt(), b = in.nextInt();
            int r = Utils.gcd(a, b);
            int MAX = 1000000;
            while (MAX % r != 0) MAX++;

            int[] ret = new int[MAX];
            // ret[i] = smallest X needed to get to square i.
            Arrays.fill(ret, MAX + 1);
            ret[0] = 0;
            PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>();

            pq.add(new Pair<>(0, 0));
            while (pq.size() > 0) {
                Pair<Integer, Integer> t = pq.poll();
                if (ret[t.v] != t.u) continue;
                for (int nxt : new int[]{t.v - b, t.v + a}) {
                    if (nxt >= 0 && nxt < MAX) {
                        int ncost = Math.max(ret[t.v], nxt);
                        if (ncost < ret[nxt]) {
                            pq.add(new Pair<>(ret[nxt] = ncost, nxt));
                        }
                    }
                }
            }
            long ans = 0;
            for (int i = 0; i < MAX && i <= m; i++) {
                if (ret[i] > MAX) continue; // cannot hit this square
                ans += Math.max(0, Math.min(m, MAX - 1) - ret[i] + 1);
            }
            // for all i >= max, f(i) = floor(i/r)+1

            if (m > MAX) {
                while (m % r != 0) {
                    ans += m / r + 1;
                    m--;
                }
                ans += m / r + 1;
                m--;
                long lo = MAX / r + 1, hi = m / r + 1;
                long sum = (lo + hi) * (hi - lo + 1) / 2;
                ans += sum * r;
            }

            out.println(ans);
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

    static class Utils {
        public static int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
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

        public void println(long i) {
            writer.println(i);
        }

    }

    static class Pair<U extends Comparable<U>, V extends Comparable<V>> implements Comparable<Pair<U, V>> {
        public final U u;
        public final V v;

        public Pair(U u, V v) {
            this.u = u;
            this.v = v;
        }

        public int hashCode() {
            return (u == null ? 0 : u.hashCode() * 31) + (v == null ? 0 : v.hashCode());
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<U, V> p = (Pair<U, V>) o;
            return (u == null ? p.u == null : u.equals(p.u)) && (v == null ? p.v == null : v.equals(p.v));
        }

        public int compareTo(Pair<U, V> b) {
            int cmpU = u.compareTo(b.u);
            return cmpU != 0 ? cmpU : v.compareTo(b.v);
        }

        public String toString() {
            return String.format("[Pair = (%s, %s)", u.toString(), v.toString());
        }

    }
}

