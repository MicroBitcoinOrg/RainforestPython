from setuptools import setup, Extension

rainforest_module = Extension('rainforest_hash', sources=['rainforesthashmodule.c', 'rainforest.c', 'rfv2_core.c'])

setup(name='rainforest_hash',
       version='0.2.0',
       description='Python module for Rainforest hash algorithms.',
       maintainer='iamstenman',
       maintainer_email='iamstenman@protonmail.com',
       url='https://github.com/MicroBitcoin/RainforestPython',
       keywords=['rainforest'],
       ext_modules=[rainforest_module])
