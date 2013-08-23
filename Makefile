SUBDIRS= src

.PHONY: all clean

all:
	@for FILE in $(SUBDIRS); do   \
	  $(MAKE) -C $$FILE;          \
	done

clean:
	@for FILE in $(SUBDIRS); do   \
	  $(MAKE) -C $$FILE clean;    \
	done

mrproper:
	@for FILE in $(SUBDIRS); do   \
	  $(MAKE) -C $$FILE mrproper; \
	done
