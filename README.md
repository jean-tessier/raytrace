# raytrace

A raytracer to teach myself some basic aspects of TDD and improve my C++ skills!

![simple scene](https://raw.githubusercontent.com/jean-tessier/raytrace/master/images/img.jpg)

## Instructions

### Requirements

- Make
- g++

### Running on Linux

- Clone the repository locally with `git clone https://github.com/jean-tessier/raytrace.git`
- Enter the directory in which the repository was cloned (e.g. `cd raytrace`)
- Build the executable with `make`
- Run the newly built executable: `./main`

### Optional command line flags

- `-i` (type: string) defines the input file (by default, world.txt)
  - see `world.txt` for file formatting example
- `-o` (type: string) defines the output file (by default, img.ppm)
  - while you can name the output file anything, the binary information will only be written as specified by the `.ppm` format
- `-w` (type: double) defines the width of the output image in pixels
- `-h` (type: double) defines the height of the output image in pixels

## TODO

- [ ] Implement other shapes
  - [x] sphere
  - [ ] bounded plane
  - [ ] others?
- [ ] Implement lighting
- [ ] Implement reflection
- [ ] Implement refraction

## COMPLETED
- [x] Implement xml parsing for world data
- [x] Implement reasonable fileHandler tests
- [x] Implement xml parsing for camera data

## WON'T DO OR NO LONGER RELEVANT
- [ ] ~~FIX: y is inverted for some reason~~
