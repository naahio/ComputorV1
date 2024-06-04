import java.util.regex.*;
import java.util.ArrayList;
import java.util.List;

public class Computor {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide an equation as input.");
            return;
        }

        String equation = args[0];
        String[] equationSides = equation.split("=");

        List<Double> lhsCoefficients = new ArrayList<>();
        List<Integer> lhsExponents = new ArrayList<>();
        List<Double> rhsCoefficients = new ArrayList<>();
        List<Integer> rhsExponents = new ArrayList<>();

        // Process the left-hand side
        processSide(equationSides[0], lhsCoefficients, lhsExponents, true);
        // Process the right-hand side
        processSide(equationSides[1], rhsCoefficients, rhsExponents, false);

        // Subtract coefficients on the RHS from coefficients on the LHS
        for (int i = 0; i < rhsCoefficients.size(); i++) {
            lhsCoefficients.set(i, lhsCoefficients.get(i) + rhsCoefficients.get(i));
        }

        // Combine exponents from both sides
        lhsExponents.addAll(rhsExponents);

        System.out.println("Reduced form: " + getReducedForm(lhsCoefficients, lhsExponents));
        int degree = getPolynomialDegree(lhsExponents);
        System.out.println("Polynomial degree: " + degree);

        switch (degree) {
            case 0:
                solveDegreeZero(lhsCoefficients);
                break;
            case 1:
                solveDegreeOne(lhsCoefficients);
                break;
            case 2:
                solveDegreeTwo(lhsCoefficients);
                break;
            default:
                System.out.println("The polynomial degree is greater than 2. I can't solve it.");
        }
    }

    public static void processSide(String side, List<Double> coefficients, List<Integer> exponents, boolean isLHS) {
        String patternStr = "([-+]?)\\s*(\\d*\\.?\\d*)\\s*\\*\\s*X\\^(\\d+)";
        Pattern pattern = Pattern.compile(patternStr);
        Matcher matcher = pattern.matcher(side);
        while (matcher.find()) {
            double coefficient = Double.parseDouble(matcher.group(1) + matcher.group(2));
            if (!isLHS)
                coefficient = -coefficient;
            int exponent = Integer.parseInt(matcher.group(3));
            coefficients.add(coefficient);
            exponents.add(exponent);
        }
    }

    public static String getReducedForm(List<Double> coefficients, List<Integer> exponents) {
        StringBuilder sb = new StringBuilder();
        boolean isFirstTerm = true;

        for (int i = 0; i < coefficients.size(); i++) {
            double coeff = coefficients.get(i);
            int exp = exponents.get(i);

            if (coeff != 0) {
                if (!isFirstTerm) {
                    sb.append(" ");
                    sb.append(coeff > 0 ? "+ " : "- ");
                    sb.append(Math.abs(coeff));
                    sb.append(" * X^");
                    sb.append(exp);
                } else {
                    isFirstTerm = false;
                    sb.append(coeff);
                    sb.append(" * X^");
                    sb.append(exp);
                }
            }
        }

        if (sb.length() == 0) {
            sb.append("0");
        }

        sb.append(" = 0");
        return sb.toString();
    }

    public static int getPolynomialDegree(List<Integer> exponents) {
        int maxDegree = 0;
        for (int exp : exponents) {
            if (exp > maxDegree) {
                maxDegree = exp;
            }
        }
        return maxDegree;
    }

    public static void solveDegreeZero(List<Double> coefficients) {
        double constantTerm = coefficients.get(0);
        if (constantTerm == 0) {
            System.out.println("Every real number ( in R ) is a solution.");
        } else {
            System.out.println("There is no solution ( in R ) .");
        }
    }

    public static void solveDegreeOne(List<Double> coefficients) {
        double a = coefficients.get(0);
        double b = coefficients.get(1);

        double solution = -a / b;
        System.out.println("The solution is:");
        System.out.println(solution);
    }

    public static void solveDegreeTwo(List<Double> coefficients) {
        double a = coefficients.get(2);
        double b = coefficients.get(1);
        double c = coefficients.get(0);

        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + Math.sqrt(discriminant)) / (2 * a);
            double root2 = (-b - Math.sqrt(discriminant)) / (2 * a);
            System.out.println("Discriminant is strictly positive, the two solutions are:");
            System.out.println(root1);
            System.out.println(root2);
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            System.out.println("Discriminant is zero, the solution is:");
            System.out.println(root);
        } else {
            System.out.println("Discriminant is strictly negative, there are no real solutions.");
        }
    }
}
