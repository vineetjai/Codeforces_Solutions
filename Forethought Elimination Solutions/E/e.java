import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        HotIsCold solver = new HotIsCold();
        solver.solve(1, in, out);
        out.close();
    }

    static class HotIsCold {
        int MAXN = 100010;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            int[] arr = in.readIntArray(n);

            HotIsCold.SegmentTree rt = new HotIsCold.SegmentTree(0, MAXN);
            for (int i = 0; i < q; i++) {
                char c = in.nextChar();
                int x = in.nextInt();
                int v = Math.abs(x);
                if (c == '>') {
                    int add = x < 0 ? 0 : 1;
                    rt.modify(v + add, MAXN, 3);
                    if (x < 0) {
                        rt.modify(1, v - 1, -1);
                    }
                } else {
                    int add = x > 0 ? 0 : 1;
                    rt.modify(v + add, MAXN, 2);
                    if (x > 0) {
                        rt.modify(1, v - 1, -1);
                    }
                }
            }

            int[] vf = new int[MAXN];
            for (int i = 0; i < MAXN; i++) {
                vf[i] = rt.query(i);
            }

            for (int i = 0; i < arr.length; i++) {
                if (i != 0) out.print(" ");
                int e = Math.abs(arr[i]);
                int b = vf[e];
                int ans;
                if (b == 0) ans = arr[i];
                else if (b == 1) ans = -arr[i];
                else if (b == 2) ans = e;
                else ans = -e;
                out.print(ans);
            }
            out.println();
        }

        static class SegmentTree {
            public HotIsCold.SegmentTree left;
            public HotIsCold.SegmentTree right;
            public int start;
            public int end;
            public int lazyflip;
            public int lazyset;

            public SegmentTree(int start, int end) {
                this.start = start;
                this.end = end;
                this.lazyset = -1;
                this.lazyflip = 0;
                if (start != end) {
                    int mid = (start + end) / 2;
                    this.left = new HotIsCold.SegmentTree(start, mid);
                    this.right = new HotIsCold.SegmentTree(mid + 1, end);
                }
            }

            public void push() {
                if (left != null) {
                    if (lazyset != -1) {
                        left.set(lazyset);
                        right.set(lazyset);
                    } else {
                        left.flip(lazyflip);
                        right.flip(lazyflip);
                    }
                    lazyset = -1;
                    lazyflip = 0;
                }
            }

            public void flip(int q) {
                if (lazyset != -1) lazyset ^= q;
                else lazyflip ^= q;
            }

            public void set(int q) {
                lazyset = q;
                lazyflip = 0;
            }

            public void modify(int s, int e, int v) {
                if (s > e) return;
                if (start == s && end == e) {
                    if (v == -1) flip(1);
                    else set(v);
                    return;
                }
                push();
                int mid = (start + end) / 2;
                if (e <= mid) left.modify(s, e, v);
                else if (mid < s) right.modify(s, e, v);
                else {
                    left.modify(s, mid, v);
                    right.modify(mid + 1, e, v);
                }
            }

            public int query(int p) {
                if (start == p && end == p) return lazyset == -1 ? lazyflip : lazyset;
                push();
                int mid = (start + end) / 2;
                if (p <= mid) return left.query(p);
                else return right.query(p);
            }

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

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
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

        public char nextChar() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            return (char) c;
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

    }
}

