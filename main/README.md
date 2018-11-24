# Bot Design Ideas

## Alpha bot
* Key idea: just basic implementation for integrity testing

* Scheduling: Navigation happens in timer interrupt. Puzzles are solved in an infinite
    loop in main function

* Navigation: Do path planning and request for new timer interrupt after the bot
    moves one block.

* Path planning: BFS

* Decision making: stick to the assigned target until reach and get the treasure.
    After getting the treasure, set the target to the nearest treasure (under
        simple distance metric such as Manhattan distance or Euclidean).

### Benchmark
* score: 5 with -mapseed 233
* cycles spent in bfs function: ~5 million
* cycles spent in preprocessing: ~5 million

## The. Alpha. Navigator
* Key idea: flood fill when dynamically navigating/update weight matrix with BFS when
    changing destination

* Other function to be optimized:

### Benchmark
* score: 4 with -mapseed 233
* cycles spent in flood fill function: ~300k
* cycles spent in bfs_weight_update: ~120k per run
* cycles spent in preprocessing: ~10m (WTF?)

# Deprecated Design

## Beta bot: Alpha bot
* Key idea: Inertial navigation to reduce cycles spent on path planning. Note that
    if we set the inertial blocks number to 1, it's equivalent to Alpha bot.

* Navigation: It move multiple blocks (which is a hyperparameter and can be tuned)
    after carrying out one path planning.

## Beta gold digger
* Key idea: similar to Beta bot but it has preference for big treasure.

### TODO
* Decision making: **Is there any smarter way?**

## Explore and Exploit bot
* Key idea: first explore the map (and obtain prizes at the same time) and after having
    some information (this should be a tunable parameter), it does efficient path planning
    in a complete sequence in this specific area.

### TODO
* Trial: try explore algorithm (e.g. turn right bot)
