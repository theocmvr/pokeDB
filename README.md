# ***Pokemon App DB*** 
## Purposes and Funccionalitties
This application was created with the objective of making traditional Pokemon information easy for local access, for example, while you play a Pokemon game and want to know some information about your next catch. This application can be scalated for newer generations of Pokemon whilst still keeping its original motivation.
These are the primary funccionalitties:
    
1. List first gen Pokemon;
2. Display primary information of Pokemon;  
3. Easy and quick search.

## System Architeture and Design

```mermaid
flowchart TB
    main["main.cpp<br/>"] -- initializes app --> il["Dear ImGui Interface<br/>- User input handling<br/>- Menu and search"]
    il -- API calls --> ll["Request Handling<br/>- Pokémon search<br/>- Validation<br/>- Data processing"]
    ll -- data access --> dl["Database<br/>- CSV parsing<br/>- Pokémon details"]
    dl --> lf["Raw Data<br/>(CSV files)"]

    classDef main fill:#4DA3FF,color:#000,stroke:#0B3C5D,stroke-width:2.5px
    classDef layer fill:#E6E6FA,color:#000,stroke:#4B0082,stroke-width:2px
    classDef assets fill:#C7E59E,color:#000,stroke:#4F772D,stroke-width:2px


    class main main
    class il,ll,dl layer
    class lf assets
```

### Requirements
- C++17 compatible compiler
- CMake ≥ 3.16
- OpenGL
- GLFW

### Build
```bash
mkdir build
cd build
cmake ..
make
```