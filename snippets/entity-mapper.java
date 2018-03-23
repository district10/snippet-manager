import org.modelmapper.ModelMapper;
import org.modelmapper.convention.MatchingStrategies;

import java.util.List;
import java.util.stream.Collectors;

public final class EntityMapper {
    private static ModelMapper mapper;
    static {
        mapper = new ModelMapper();
        mapper.getConfiguration().setMatchingStrategy(MatchingStrategies.STRICT);
    }
    // Java 比较奇怪的地方, 如果没有别的 ctor, 就需要加这个来屏蔽它 (防止自动生成 ctor)
    private EntityMapper() { }

    public static <T> T mapTo(Object object, Class<T> type) {
        return mapper.map(object, type);
    }
    public static <R, T> List<T> mapToList(List<R> list, Class<T> type) {
        return list.stream().map(o -> mapper.map(o, type)).collect(Collectors.toList());
    }
}
