---
title: kinodynamic_motion_planning
categories: motion planning
tags: kinodynamic
date: 2023-02-04
---  


- [bench-mr](https://github.com/robot-motion/bench-mr)
- [chomp-multigrid](https://github.com/eric-heiden/chomp-multigrid/tree/4cd8abef27e51204a0cdd2b3ce411b88eee411c0)
https://github.com/sailist/Awesome-Paper-List-py/blob/master/pdfs/sync-bypy.py
## ref

- blog
    - [MOTION PLANNING](http://motion.cs.illinois.edu/RoboticSystems/PlanningWithDynamicsAndUncertainty.html)
    - [Path Planning for a Simple Car](https://jckantor.github.io/ND-Pyomo-Cookbook/notebooks/06.03-Path-Planning-for-a-Simple-Car.html)
    - [Notebook 7.1 - Introduction to Trajectory Optimisation in Python](https://transport-systems.imperial.ac.uk/tf/60008_21/n7_1_introduction_to_trajectory_optimisation.html)
- paper
    - [2022 db-A*: Discontinuity-bounded Search for Kinodynamic Mobile Robot Motion Planning](https://arxiv.org/abs/2203.11108)
    - [2017-A tutorial on newton methods for constrained trajectory optimization and relations to slam, gaussian process smoothing, optimal control, and probabilistic inference](https://argmin.lis.tu-berlin.de/papers/17-toussaint-Newton.pdf)
    - [2008-kpiece:Kinodynamic Motion Planning by Interior-Exterior Cell Exploration](https://ioan.sucan.ro/files/pubs/wafr2008.pdf)
    - [An Optimization-Based Motion Planner for Car-like Logistics Robots on Narrow Roads]()
- book
    - [Robotic Systems](https://motion.cs.illinois.edu/RoboticSystems/)
- library
    - * Search-based: ARA* (using SBPL http://www.sbpl.net/)
    - * Sampling-based: SST* (using OMPL https://ompl.kavrakilab.org/)
    - * Optimization-based: KOMO(K-Order Markov Optimization) (using RAI https://github.com/MarcToussaint/rai)
        - [doc](https://github.com/MarcToussaint/rai/wiki)
    - * [Hybrid: db-A*](https://github.com/IMRCLab/kinodynamic-motion-planning-benchmark)