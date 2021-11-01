### Description
Found an interesting repo by Tim Paine for JP Morgan about python coding for algorithms:
https://github.com/jpmorganchase/python-training
( note: this repository writes code in Jupyter IPython notebook )

### Financial Notes

ATMF Formula (Black Scholes Formula - 2_straddle.ipynb)
    link:   https://quant.stackexchange.com/questions/1150/what-are-some-useful-approximations-to-the-black-scholes-formula


### General Notes
VCS:
    Version control system

pylance:
    Microsoft, fast and feature-rich language support for Python, available in vscode

pyright:
    Pyright is a fast type checker meant for large Python source bases. It can run in 
    a “watch” mode and performs fast incremental updates when files are modified
    Link : Pyright is a fast type checker meant for large Python source bases. It can 
           run in a “watch” mode and performs fast incremental updates when files are modified

Jupyter IPython notebook:
    don't nee %matlablib inline if not using this. JupyterLab is a web-based interactive 
    development environment for Jupyter notebooks, code, and data. 

### Dependencies
pytest (unit testing)
    pip install pytest

matplotlib
    pip install matplotlib

anaconda3 
( not sure if its needed or not. I read it gives a good amount of general libs and matplotlib )
link: https://www.anaconda.com/products/individual
This should have downloaded pandas.... but it didn't seem to load for me

pandas
    pip install wheel
    pip install pandas

perspective
    pip3 install perspective-python
        (didn't need to install) pip3 install imutils
        (didn't need to install) pip3 install perspective
        (didn't need to install) pip3 install psp    
        " ERROR: Could not build wheels for perspective-python, which is required to install pyproject.toml-based projects "
        https://github.com/finos/perspective/issues/1251
    pip3 install ipywidgets jupyterlab
    pip3 install python.node
    Doesn't seem to be working on vscoikjuygtfrded bs wade


jupyter
-   Vscode extensions

### Issues:
ex1.ipynb
    1. didn't recognize numpy:
        SOLUTION:   disable pyright and pylance extensions. Make sure its downloaded
    2. didn't recognize matlibplot:
        SOLUTION:   Changed debugger to python3.9.7 (opt/homebrew/bin/python3) from python3.8.9 (usr/bin/python3) 
        


    

    