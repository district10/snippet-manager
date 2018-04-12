@Enumerated(EnumType.STRING)
private Usability usability;

public enum Usability {
    AVAILABLE,
    NOT_AVAILABLE,
    IN_MIGRATION
}

Usability.AVAILABLE.name(); // "AVAILABLE"
