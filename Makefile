SUBDIRS= src

.PHONY: all test runtest clean mrproper

all:
	@for FILE in $(SUBDIRS); do   \
	  $(MAKE) -C $$FILE;          \
	done

test:
	@for FILE in $(SUBDIRS); do   \
	  $(MAKE) -C $$FILE test;     \
	done

runtest:
	@for FILE in $(SUBDIRS); do   \
	  $(MAKE) -C $$FILE runtest;  \
	done

clean:
	@for FILE in $(SUBDIRS); do   \
	  $(MAKE) -C $$FILE clean;    \
	done

mrproper:
	@for FILE in $(SUBDIRS); do   \
	  $(MAKE) -C $$FILE mrproper; \
	done
