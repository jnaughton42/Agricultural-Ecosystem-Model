# Project for the Consortium for Mathematics and its Applications (COMAP) Interdisciplinary Competition in Modelling (ICM)

**Honorable mention winner (Ctrl #: 2527078):** [COMAP ICM Problem E 2025 Results](https://www.contest.comap.com/undergraduate/contests/mcm/contests/2025/results/2025_ICM_Problem_E_Results.pdf)

**Team: Jeremiah Naughton (coding), Jasmine Reid (data collection and report writing), Sarah Jameson (data collection and report writing)**

---

## Description

This project attempts to model the intertwined, interdependent causal web dynamics of a preset ecosystem re-emerging after conversion into farmland. Each animal type is organized into a class meant to be instantiated only once 
(populations are tracked within single object for performance reasons), each class has a number of member functions meant to simulate certain interactions (reproduction, consumption, aging, etc.).
The consumption of prey adjusts dynamically based on existing population levels, how much energy each member of that population can provide, and evasive capability of said prey.

These functions are called on a monthly update cycle along with other functions that simulate various environmental effects. Certain global values can be set in the code to apply different effects (either in the environment
or specific actions by the farmer). 

**More detailed info on design and function in Group submission document (Math Modeling Text Submission.pdf). Please keep in mind, initial submission was written/coded over a single weekend.**

## Issues

The data gathered to inform the mathematical relationships in this simulation is incredibly imperfect and unreliable. Due to the extreme time constraints of the project, sourcing data ourselves was not an option,
as such, data on animal diets, caloric intake, reproduction, and a variety of other things were sourced from various websites. On top of that, for the sake of the stability of the simulated ecosystems, 
these relationships needed to be tweaked. 

Also, as is the reality with any simulation, but especially one created in two days with unreliable data, this simulation does not cover nearly all the factors in a real ecosystem, nor their complexity.
The representation of most of these relationships, although intertwined, is rather mathematically simple due to time constraints.
Given these things, it is no surprise that the simiualtion is very unstable and usually experiences some sort of ecosystem collapse relatively quickly (showing how complex and delicate real world ecosystems are).

Despite all of these issues, non-obvious causal chains can be observed in some simulations, implying some level of viability.

## Potential Future Improvements

- Professionally sourced data
- Greater consistency between sourced data and mathematical implementation
- Improvements to code structure (an abstract animal class would likely cut down on total lines and improve readability significantly)
- Implementation of a more robust financial model (original goal was to model economic impacts of agricultural decisions relative to their effects on the ecosystem)
- Greater complexity (more complex/accurate mathematical relationships, more species considered, more variables taken into account)
- Use of either differential equations or linear algebra to model concurrent mathematical effects as opposed to random ordering each month
