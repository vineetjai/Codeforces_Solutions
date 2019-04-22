import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        SatanicPanic2 solver = new SatanicPanic2();
        solver.solve(1, in, out);
        out.close();
    }

    static class SatanicPanic2 {
        public static boolean ccw(AngleAreaOrientationSortRotationPerpendicular.Point p, AngleAreaOrientationSortRotationPerpendicular.Point r) {
            return 1L * (r.y - p.y) * p.x < 1L * p.y * (r.x - p.x);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            AngleAreaOrientationSortRotationPerpendicular.Point[] ps = new AngleAreaOrientationSortRotationPerpendicular.Point[n];
            for (int i = 0; i < n; i++) {
                ps[i] = new AngleAreaOrientationSortRotationPerpendicular.Point(in.nextInt(), in.nextInt(), i + 1);
            }
            Arrays.sort(ps, (a, b) -> ((a.x == b.x ? a.y - b.y : a.x - b.x)));

            AngleAreaOrientationSortRotationPerpendicular.Point[] other = new AngleAreaOrientationSortRotationPerpendicular.Point[3 * (n - 1)];
            long ans = 0;
            for (int bottom = 0; bottom < n; bottom++) {
                int[][][] count = new int[2][n][n];
                for (int pivot = bottom + 1; pivot < n; pivot++) {
                    for (int k = 0; k < 2; k++) {
                        int idx = 0;
                        for (int i = bottom; i < n; i++) {
                            if (i != pivot) {
                                other[idx++] = new AngleAreaOrientationSortRotationPerpendicular.Point(ps[i].x - ps[pivot].x, (k == 0 ? 1 : -1) * (ps[i].y - ps[pivot].y), i);
                            }
                        }
                        Arrays.sort(other, 0, idx);
                        for (int i = 0; i < idx; i++) other[i + 2 * idx] = other[i + idx] = other[i];

                        int start = 0;
                        for (int i = 0; i < idx; i++) {
                            if (other[i].id == bottom) {
                                start = i;
                                break;
                            }
                        }

                        int dd = -1;
                        for (int i = 1; i < idx; i++) {
                            if (ccw(other[start], other[start + i])) {
                                dd = start + i;
                                break;
                            }
                        }

                        if (dd == -1) continue;

                        int back = start;
                        for (int i = 0; i < idx; i++) {
                            if (other[i + dd].id == bottom) break;
                            while (back < i + dd && !ccw(other[i + dd], other[back])) back++;
                            count[k][pivot][other[i + dd].id] = back - start - 1;
                        }
                    }
                }

                for (int i = bottom + 1; i < n; i++) {
                    for (int j = bottom + 1; j < n; j++) {
                        ans += count[0][i][j] * count[1][j][i];
                    }
                }
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

    static class AngleAreaOrientationSortRotationPerpendicular {
        public static class Point implements Comparable<AngleAreaOrientationSortRotationPerpendicular.Point> {
            public int x;
            public int y;
            public int id;

            public Point(int x, int y, int id) {
                this.x = x;
                this.y = y;
                this.id = id;
            }

            public Point(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public int compareTo(AngleAreaOrientationSortRotationPerpendicular.Point o) {
                boolean up1 = y > 0 || (y == 0 && x >= 0);
                boolean up2 = o.y > 0 || (o.y == 0 && o.x >= 0);
                if (up1 != up2) return up1 ? -1 : 1;
                int cmp = Long.signum((long) o.x * y - (long) o.y * x);
                if (cmp != 0) return cmp;
                return Long.compare((long) x * x + (long) y * y, (long) o.x * o.x + (long) o.y * o.y);
                //return Double.compare(Math.atan2(y, x), Math.atan2(o.y, o.x));
            }

            public String toString() {
                return "(" + x + ',' + y + ')';
            }

        }

    }
}

