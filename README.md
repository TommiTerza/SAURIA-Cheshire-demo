# SAURIA-Cheshire Demo

This repository contains a demonstration of the integration of the SAURIA convolutional accelerator and CHESHIRE MCU. The project includes source code, hardware design files, and supporting scripts for simulation and FPGA deployment.

## Project Structure

- **`hw/`**: Hardware design files, including SystemVerilog modules and packages.
  - `axi_intfc_bridge.sv`, `axi_lite_intfc_bridge.sv`, `sauria_demo_soc.sv`: Core hardware modules.
  - `include/`: Contains reusable hardware packages like `sauria_demo_pkg.sv`.

- **`sw/`**: Software components for the SoC.
  - `data/`: Input, weight, and output tensor data files.
  - `lib/`: Utility libraries and headers for software development.
  - `src/`: Source files for software applications, such as `sauria_conv_single_layer.c`.

- **`target/`**: Target-specific files for FPGA and simulation.
  - `fpga/`: FPGA-related files.
  - `sim/`: Simulation files, including source and ModelSim configurations.

- **`vendor/`**: Dependencies and submodules.
  - `cheshire/`: Cheshire-related files.
  - `SAURIA/`: SAURIA-related files.

- **Root Files**:
  - `.gitignore`: Git ignore rules.
  - `Bender.yml`: Dependency management configuration.
  - `Makefile`: Build automation script.
  - `README.md`: Project documentation.
  - `sauria_demo.mk`: Makefile for the SAURIA demo.

## Getting Started

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd SAURIA-Cheshire-demo
   ```

2. Build the hardware model:
   ```bash
   make hw-all
   ```


## License

This project is licensed under the terms specified in the repository. Please refer to the license file for details.

## Acknowledgments

This project has been developed as part of the project NODES which has received funding from the MI_JQ—M4C215 of PNRR funded by the European Union - NextGenerationEU (Grant agreement no. ECSOOOOOOB6)
