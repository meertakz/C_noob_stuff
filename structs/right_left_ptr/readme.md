Let the command line parameters be the following

file.txt Giallo_Antonio ---+

and the input file be the following

Rossi_Alberto A1B1C1D1E1F1G1H1 03.12.1998 1845

Giallo_Antonio A2B2C2D2E2F2G2H2 13.11.2007 1140

Verdi_Federica A3B3C3D3E3F3G3H3 25.09.1989 2157

Bianchi_Elena A4B4C4D4E4F4G3H4 15.02.2004 1345


The file has to be stored in the LIFO structure as:
Bianchi  ->  Verdi  -> Giallo  -> Rossi  
Then, the program has to:
- find Giallo_Antonio in the list and print its data
- move left on Verdi and print its data (first -)
- move left again and print Bianchi (second -)
- do not move and print Bianchi again (third -)
- move right and print Verdi (first +):
___________________________________________________

Giallo_Antonio A2B2C2D2E2F2G2H2 13.11.2007 1140

Verdi_Federica A3B3C3D3E3F3G3H3 25.09.1989 2157

Bianchi_Elena A4B4C4D4E4F4G3H4 15.02.2004 1345

Bianchi_Elena A4B4C4D4E4F4G3H4 15.02.2004 1345

Verdi_Federica A3B3C3D3E3F3G3H3 25.09.1989 2157
