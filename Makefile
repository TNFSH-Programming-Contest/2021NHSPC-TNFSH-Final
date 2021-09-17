nothing:

import-pA:
	cmsImportTask ./pA/ -u $(if $(s), , --no-statement)

import-pB:
	cmsImportTask ./pB/ -u $(if $(s), , --no-statement)

import-pC:
	cmsImportTask ./pC/ -u $(if $(s), , --no-statement)

import-pD:
	cmsImportTask ./pD/ -u $(if $(s), , --no-statement)

import-pE:
	cmsImportTask ./pE/ -u $(if $(s), , --no-statement)

import-pF:
	cmsImportTask ./pF/ -u $(if $(s), , --no-statement)
