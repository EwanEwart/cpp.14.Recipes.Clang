# ManagedObject
```puml
'black background
'skinparam backgroundColor transparent
skinparam backgroundColor #EEEAD0

class ManagedObjectCollection <<static>>
class FreeList <<static>>

ManagedObject "many" *-- "1" ManagedObjectCollection: contains
ManagedObject "many" *-- "1" FreeList: contains
```
