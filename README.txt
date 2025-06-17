Another legal XML tag not used is the "stand-alone" tag. This kind of tag combines both a start-tag and end-tag in one. It is identified with a '/' (slash) preceding the final >. (For example, the <foo/> is a stand-alone tag that is "self balancing".

Describe briefly how you would modify Requirement 1 to allow this kind of tag.


Changing the part of the code in main where it reads the tags to:

1) Searching up characters with / behind it.
2) Adding searched up characters from step 1 to hash table.
