# Concurrency Exercise List

## Readers and Writers

We have a database accessed by two types of processes: readers and writers. Reader processes query records from the database, while writer processes modify those records. The database can be accessed concurrently, but it needs to be controlled to prevent data corruption. To achieve this, the following rules must be followed:

* Multiple readers can work concurrently.
* If a writer tries to access the database while readers are active, the writer must wait for the database to become available.
* While a writer is working with the database, no other processes (neither readers nor writers) can be active.

There are two specifications for the system, depending on how priority is given to readers or writers when the database becomes available:

* In the first reader-writer problem, a reader process can enter as soon as possible.
* In the second reader-writer problem, as soon as a writer is waiting to enter the database, incoming readers must wait, even if there are only readers currently working in the database.
