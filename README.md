# Kraken2
# Language: C++
# Input: TXT
# Output: TXT
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: Kraken 2.1.2

Map sequences to taxa and counts, using Kraken
Note this depends on the environment variable KRAKEN2_DB being set properly

The plugin accepts as input a TXT file of tab-delimited keyword-value pairs:
forward: FASTQ file for forward sequences
reverse: FASTQ file for reverse sequences

Taxa and counts will be sent to the provided output file
