list.stream().sorted(Comparator.comparing(T::getA).thenComparing(T::getB));
