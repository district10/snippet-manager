// method 1
@Service
public class InjectableService {
    private FileService fileService;
    public InjectableService(FileService fileService) {
        this.fileService = fileService;
    }
}

// method 2
@Service
public class InjectableService {
    @Autowired
    private FileService fileService;
}

// inject mocks
class InjectableServiceTest {
    @InjectMocks
    private InjectableService injectableService;
    @Mock
    private FileService fileService;
    @BeforeEach
    void setUp() {
        initMocks(this);
    }
}
