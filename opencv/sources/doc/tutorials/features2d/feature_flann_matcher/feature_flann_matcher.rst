.. _feature_flann_matcher:

Feature Matching with FLANN
****************************

Goal
=====

In this tutorial you will learn how to:

.. container:: enumeratevisibleitemswithsquare

   * Use the :flann_based_matcher:`FlannBasedMatcher<>` interface in order to perform a quick and efficient matching by using the :flann:`FLANN<>` ( *Fast Approximate Nearest Neighbor Search Library* )


Theory
======

Code
====

<<<<<<< HEAD
This tutorial code's is shown lines below. You can also download it from `here <https://github.com/Itseez/opencv/tree/master/samples/cpp/tutorial_code/features2D/SURF_FlannMatcher.cpp>`_
=======
This tutorial code's is shown lines below. You can also download it from `here <https://github.com/opencv/opencv/tree/master/samples/cpp/tutorial_code/features2D/SURF_FlannMatcher.cpp>`_
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

.. literalinclude:: ../../../../samples/cpp/tutorial_code/features2D/SURF_FlannMatcher.cpp
   :language: cpp

Explanation
============

Result
======

#. Here is the result of the feature detection applied to the first image:

   .. image:: images/Featur_FlannMatcher_Result.jpg
      :align: center
      :height: 250pt

#. Additionally, we get as console output the keypoints filtered:

   .. image:: images/Feature_FlannMatcher_Keypoints_Result.jpg
      :align: center
      :height: 250pt
