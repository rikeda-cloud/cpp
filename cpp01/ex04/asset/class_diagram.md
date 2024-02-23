```mermaid
classDiagram

FILEREADER <|-- INFILEREADER
FILEREADER <|-- OUTFILEREADER

class REPLACER["Replacer"] {
    +void           replace(string& string, string& from, string& to)
}

class FILEREADER["FileReader"] {
    -string fname;
    -bool   is_fail;

    -int    open(void);
    -void   close(void);

    +isFail(void);
}

class INFILEREADER["InFileReader"] {
    -ifstream   fs;
    +getAllChars(void);
}

class OUTFILEREADER["OutFileReader"] {
    -ofstream   fs;
    +save(void);
}

```
