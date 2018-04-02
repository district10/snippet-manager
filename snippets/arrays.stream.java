Arrays.stream(str.split("/"))
        .map(s -> s.length())
        .collect(Collectors.toSet());
