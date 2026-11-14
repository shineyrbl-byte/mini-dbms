# Mini DBMS

A small relational database engine written from scratch in modern C++, built to understand how databases work under the hood.

> **Status: early work in progress.** The type system, schemas and in-memory tables with insert-time validation work today. Storage, indexing and a query layer are next.

## What works today

- **Typed values:** `INT`, `FLOAT` and `TEXT`, stored in a type-safe `std::variant<int, float, std::string>`.
- **Schemas:** a table schema is an ordered list of named, typed columns.
- **Tables with validation:** `Table::insertRow` accepts a row only if it has the right number of values and every value matches its column's type. Otherwise it rejects the row and returns `false`.
- **Database catalog:** a `Database` holds tables and looks them up by name.

## Example

```cpp
Schema studentSchema({
    Column("id",   DataType::INT),
    Column("name", DataType::TEXT),
    Column("cgpa", DataType::FLOAT)
});

Table students("students", studentSchema);

students.insertRow(Row({ Value(101), Value(std::string("Avisha")), Value(8.8f) }));  // true
students.insertRow(Row({ Value(102), Value(std::string("Rahul")) }));                // false: missing a column
students.insertRow(Row({ Value(std::string("Avisha")), Value(103), Value(8.5f) }));  // false: wrong types
```

## Build and run

Requires CMake 3.16+ and a C++17 compiler.

```bash
cmake -S . -B build
cmake --build build
./build/mini_dbms
```

The demo in `src/main.cpp` prints `1`, `0`, `0`: the valid row is inserted and the two invalid rows are rejected.

## Project layout

```
src/
├── main.cpp              demo
├── types/
│   ├── DataType.h        INT / FLOAT / TEXT
│   └── Value.h           typed value (std::variant)
├── schema/
│   ├── Column.h          named, typed column
│   └── Schema.h          ordered list of columns
├── storage/
│   ├── Row.h             list of values
│   └── Table.h           rows + insert-time validation
└── database/
    └── Database.h        table catalog
```

## Roadmap

- [ ] Persist tables to disk (page-based file format)
- [ ] `SELECT` with column projection and `WHERE` filters
- [ ] `UPDATE` and `DELETE`
- [ ] Primary keys and a B+ tree index
- [ ] A small SQL parser and REPL
- [ ] Unit tests
