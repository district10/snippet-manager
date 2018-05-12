# install
    sudo apt-get install clang-format

# .clang-format (save as .clang-format in your project root)
$ clang-format -style=llvm -dump-config >> .clang-format
    Language:        Cpp
    BasedOnStyle:  LLVM
    AccessModifierOffset: -2
    AlignAfterOpenBracket: Align
    AlignConsecutiveAssignments: false
    AlignConsecutiveDeclarations: false
    AlignEscapedNewlinesLeft: false
    AlignOperands:   true
    AlignTrailingComments: true
    AllowAllParametersOfDeclarationOnNextLine: true
    AllowShortBlocksOnASingleLine: false
    AllowShortCaseLabelsOnASingleLine: false
    AllowShortFunctionsOnASingleLine: true
    AllowShortIfStatementsOnASingleLine: false
    AllowShortLoopsOnASingleLine: false
    AlwaysBreakAfterDefinitionReturnType: None
    AlwaysBreakAfterReturnType: None
    AlwaysBreakBeforeMultilineStrings: false
    AlwaysBreakTemplateDeclarations: false
    BinPackArguments: true
    BinPackParameters: true
    BraceWrapping:
      AfterFunction:   true
      AfterClass:      true
      AfterControlStatement: false
      AfterEnum:       true
      AfterNamespace:  true
      AfterObjCDeclaration: false
      AfterStruct:     true
      AfterUnion:      true
      BeforeCatch:     false
      BeforeElse:      false
      IndentBraces:    false
    BreakBeforeBinaryOperators: None
    BreakBeforeBraces: Custom
    BreakBeforeTernaryOperators: true
    BreakConstructorInitializersBeforeComma: false
    ColumnLimit:     80
    CommentPragmas:  '^ IWYU pragma:'
    ConstructorInitializerAllOnOneLineOrOnePerLine: false
    ConstructorInitializerIndentWidth: 4
    ContinuationIndentWidth: 4
    Cpp11BracedListStyle: true
    DerivePointerAlignment: false
    DisableFormat:   false
    ExperimentalAutoDetectBinPacking: false
    ForEachMacros:   [ foreach, Q_FOREACH, BOOST_FOREACH ]
    IncludeCategories:
      - Regex:           '^"(llvm|llvm-c|clang|clang-c)/'
        Priority:        2
      - Regex:           '^(<|"(gtest|isl|json)/)'
        Priority:        3
      - Regex:           '.*'
        Priority:        1
    IndentCaseLabels: false
    IndentWidth:     4
    IndentWrappedFunctionNames: false
    KeepEmptyLinesAtTheStartOfBlocks: true
    MacroBlockBegin: ''
    MacroBlockEnd:   ''
    MaxEmptyLinesToKeep: 1
    NamespaceIndentation: None
    ObjCBlockIndentWidth: 2
    ObjCSpaceAfterProperty: false
    ObjCSpaceBeforeProtocolList: true
    PenaltyBreakBeforeFirstCallParameter: 19
    PenaltyBreakComment: 300
    PenaltyBreakFirstLessLess: 120
    PenaltyBreakString: 1000
    PenaltyExcessCharacter: 1000000
    PenaltyReturnTypeOnItsOwnLine: 60
    PointerAlignment: Right
    ReflowComments:  true
    SortIncludes:    true
    SpaceAfterCStyleCast: false
    SpaceBeforeAssignmentOperators: true
    SpaceBeforeParens: ControlStatements
    SpaceInEmptyParentheses: false
    SpacesBeforeTrailingComments: 1
    SpacesInAngles:  false
    SpacesInContainerLiterals: true
    SpacesInCStyleCastParentheses: false
    SpacesInParentheses: false
    SpacesInSquareBrackets: false
    Standard:        Cpp11
    TabWidth:        4
    UseTab:          Never

# Shell
    git ls-files -m | grep -E '\.h$|\.cpp$|\.hpp$|\\.c$' | tr '\n' ' ' | clang-format -i

# Makefile
    ALL_SRCS = $(shell git ls-files    | grep -E '\.h$$|\.cpp$$|\.hpp$$|\\.c$$' | tr '\n' ' ')
    MOD_SRCS = $(shell git ls-files -m | grep -E '\.h$$|\.cpp$$|\.hpp$$|\\.c$$' | tr '\n' ' ')

    all: lint
    lint:
        clang-format -i $(MOD_SRCS)
    lintall:
        clang-format -i $(ALL_SRCS)

# VS Code integration
    -   install clang-format extension
    -   control-shift-p, user settings, put config:
            "editor.formatOnSave": true,
