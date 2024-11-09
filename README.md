# SWEN-746 Individual Assignment
Implementing Composite and Visitor design patterns into a prototype monster racing game project.

- Composite is implemented by a component-based structure, where every element in the game world is a GameObject that can have any number of Components attached to them.
Instead of handling all of the behavior on the GameObject class, execution is delegated to the Components.
- Visitor is implemented by an EvolutionVisitor, which can visit various types of Monster GameObjects, adding additional behavior without modifying the Monster class.

## Requirement Diagram
![Requirement Diagram](/assets/hw12_requirement_diagram.png)

## Class Diagram
![Class Diagram](/assets/SWEN_746_HW7_Class_Diagram.png)
