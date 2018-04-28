public boolean equals(Object obj) {
    if (obj instanceof Boolean) {
        return value == ((Boolean)obj).booleanValue();
    }
    return false;
}

if (Boolean.TRUE.equals(yourValue)) { ... }
