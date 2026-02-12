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

    classDef main fill:#CCE6FF,stroke:#222,stroke-width:2px
    classDef layer fill:#F9F9FF,stroke:#888,stroke-width:1.5px
    classDef assets fill:#F7FFE0,stroke:#88B04B,stroke-width:1.5px

    class main main
    class il,ll,dl layer
    class lf assets

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