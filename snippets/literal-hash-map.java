Map<String, String> m = new HashMap<>() {{ // initialize map (literal map)
    put("key", "value");
}};

Map<String, Integer> left = ImmutableMap.of("a", 1, "b", 2, "c", 3); // up to five

Map<String, String> test = ImmutableMap.<String, String>builder()
    .put("k1", "v1")
    .put("k2", "v2")
    ...
    .build();
