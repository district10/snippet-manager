import java.util.Optional;

public enum Status {
    A(1),
    B(2),
    C(3);

    private int code;
    Status(int code) { this.code = code; }

    public static Optional<Status> fromCode(String code) {
        try {
            return stream(values())
                .filter(status -> status.code == Integer.parseInt(code))
                .findFirst();
        } catch (Exception e) {
            return Optional.empty();
        }
    }
}
