function jMeterPut(store, jmKey, jmValues) {
    store.put(jmKey + "_#", jmValues.length);
    for (var i = 0; i < jmValues.length; i++) {
        store.put(jmKey + "_" + (i + 1), jmValues[i]);
    }
}
// jMeterPut(vars, "numbers", [1, 3, 5, 7]);
// vars.put( "key", "value" );
